//-----------------------------------------------------------------------------
// File: AdHocBoundsModel.cpp
//-----------------------------------------------------------------------------
// Project: Kactus2
// Author: Joni-Matti M��tt�
// Date: 20.2.2012
//
// Description:
// Table model for visualizing ad-hoc bounds for connection ports.
//-----------------------------------------------------------------------------

#include "AdHocBoundsModel.h"

#include "AdHocBoundColumns.h"

#include <designEditors/common/DesignDiagram.h>

#include <designEditors/HWDesign/AdHocConnectionItem.h>
#include <designEditors/HWDesign/HWConnectionEndpoint.h>
#include <designEditors/HWDesign/HWChangeCommands.h>

#include <common/IEditProvider.h>

#include <IPXACTmodels/common/PartSelect.h>

#include <IPXACTmodels/Component/Port.h>

#include <IPXACTmodels/Design/AdHocConnection.h>
#include <IPXACTmodels/Design/PortReference.h>

//-----------------------------------------------------------------------------
// Function: AdHocBoundsModel::AdHocBoundsModel()
//-----------------------------------------------------------------------------
AdHocBoundsModel::AdHocBoundsModel(QObject *parent) : QAbstractTableModel(parent),
    editProvider_(),
    connection_(0)
{

}

//-----------------------------------------------------------------------------
// Function: AdHocBoundsModel::~AdHocBoundsModel()
//-----------------------------------------------------------------------------
AdHocBoundsModel::~AdHocBoundsModel()
{
}

//-----------------------------------------------------------------------------
// Function: AdHocBoundsModel::setConnection()
//-----------------------------------------------------------------------------
void AdHocBoundsModel::setConnection(AdHocConnectionItem* connection, QSharedPointer<IEditProvider> editProvider)
{
    editProvider_ = editProvider;
    connection_ = connection;
    
    beginResetModel();
    endResetModel();
}

//-----------------------------------------------------------------------------
// Function: AdHocBoundsModel::rowCount()
//-----------------------------------------------------------------------------
int AdHocBoundsModel::rowCount(QModelIndex const& parent) const
{
    if (parent.isValid())
    {
        return 0;
    }

    return getEndpointCount();
}

//-----------------------------------------------------------------------------
// Function: AdHocBoundsModel::columnCount()
//-----------------------------------------------------------------------------
int AdHocBoundsModel::columnCount(QModelIndex const& parent) const
{
    if (parent.isValid())
    {
        return 0;
    }

    return AdHocBoundColumns::COLUMN_COUNT;
}

//-----------------------------------------------------------------------------
// Function: AdHocBoundsModel::data()
//-----------------------------------------------------------------------------
QVariant AdHocBoundsModel::data(QModelIndex const& index, int role) const
{
    // Check for invalid index.
    if (!index.isValid() || connection_ == 0 || index.row() > getEndpointCount())
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        QSharedPointer<PortReference> port = getEndpoint(index.row());

        if (index.column() == AdHocBoundColumns::NAME)
        {
            QString portName = port->getPortRef();
            if (port->getComponentRef().isEmpty())
            {
                portName.append(QStringLiteral(" (external)"));
            }

            return portName;
        }

        else if (index.column() == AdHocBoundColumns::LEFT_BOUND)
        {
            QSharedPointer<PartSelect> part = port->getPartSelect();

            if (part)
            {
                return part->getLeftRange();
            }
            else if (index.row() == 0)
            {
                return connection_->endpoint1()->getPort()->getLeftBound();
            }
            else if (index.row() == 1)
            {
                return connection_->endpoint2()->getPort()->getLeftBound();
            }
        }

        else if (index.column() == AdHocBoundColumns::RIGHT_BOUND)
        {
            QSharedPointer<PartSelect> part = port->getPartSelect();

            if (part)
            {
                return part->getRightRange();
            }
            else if (index.row() == 0)
            {
                return connection_->endpoint1()->getPort()->getRightBound();
            }
            else if (index.row() == 1)
            {
                return connection_->endpoint2()->getPort()->getRightBound();
            }
        }
    }   

    return QVariant();
}

//-----------------------------------------------------------------------------
// Function: AdHocBoundsModel::headerData()
//-----------------------------------------------------------------------------
QVariant AdHocBoundsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if (orientation == Qt::Horizontal)
    {
        if (section == AdHocBoundColumns::NAME)
        {
            return tr("Port name");
        }
        else if (section == AdHocBoundColumns::LEFT_BOUND)
        {
            return tr("Left Bound");
        }
        else if (section == AdHocBoundColumns::RIGHT_BOUND)
        {
            return tr("Right Bound");
        }
        else
        {
            return QVariant();
        }
    } 
    // Vertical headers get running numbers.
    else
    {
        return section + 1;
    }
}

//-----------------------------------------------------------------------------
// Function: AdHocBoundsModel::setData()
//-----------------------------------------------------------------------------
bool AdHocBoundsModel::setData(QModelIndex const& index, QVariant const& value, int role)
{
    // Check for invalid index.
    if (!index.isValid() || connection_ == 0 || index.row() < 0 || index.row() > getEndpointCount())
    {
        return false;
    }

    if (role == Qt::EditRole)
    {
        QSharedPointer<PortReference> port = getEndpoint(index.row());

        if (index.column() == AdHocBoundColumns::LEFT_BOUND)
        {
            QSharedPointer<QUndoCommand> cmd(new AdHocBoundsChangeCommand(port, false, value.toString()));
            editProvider_->addCommand(cmd);
            cmd->redo();

            emit dataChanged(index, index);
            return true;
        }

        else if (index.column() == AdHocBoundColumns::RIGHT_BOUND)
        {
            QSharedPointer<QUndoCommand> cmd(new AdHocBoundsChangeCommand(port, true, value.toString()));
            editProvider_->addCommand(cmd);
            cmd->redo();

            emit dataChanged(index, index);
            return true;
        }

        else
        {
            return false;
        }
    }

    return false;
}

//-----------------------------------------------------------------------------
// Function: AdHocBoundsModel::flags()
//-----------------------------------------------------------------------------
Qt::ItemFlags AdHocBoundsModel::flags(QModelIndex const& index) const
{
    if (!index.isValid())
    {
        return Qt::NoItemFlags;
    }

    if (index.column() == AdHocBoundColumns::NAME)
    {
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    }
    else if (index.column() == AdHocBoundColumns::LEFT_BOUND || index.column() == AdHocBoundColumns::RIGHT_BOUND)
    {
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
    }
    
    return Qt::NoItemFlags;
}

//-----------------------------------------------------------------------------
// Function: AdHocBoundsModel::getEndpointCount()
//-----------------------------------------------------------------------------
int AdHocBoundsModel::getEndpointCount() const
{
    if (connection_ == 0 || connection_->getAdHocConnection() == 0)
    {
        return 0;
    }

    return connection_->getAdHocConnection()->getInternalPortReferences()->count() +
        connection_->getAdHocConnection()->getExternalPortReferences()->count();
}

//-----------------------------------------------------------------------------
// Function: AdHocBoundsModel::getEndpoint()
//-----------------------------------------------------------------------------
QSharedPointer<PortReference> AdHocBoundsModel::getEndpoint(int row) const
{
    int internalPortCount = connection_->getAdHocConnection()->getInternalPortReferences()->count();
    if (row < internalPortCount)
    {
        return connection_->getAdHocConnection()->getInternalPortReferences()->at(row);
    }
    else
    {
        return connection_->getAdHocConnection()->getExternalPortReferences()->at(row - internalPortCount);
    }
}
