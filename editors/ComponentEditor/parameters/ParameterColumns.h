//-----------------------------------------------------------------------------
// File: ParameterColumns.h
//-----------------------------------------------------------------------------
// Project: Kactus2
// Author: Esko Pekkarinen
// Date: 10.11.2014
//
// Description:
// Common declarations for editing parameters.
//-----------------------------------------------------------------------------

namespace ParameterColumns
{
    //! The editable columns in the parameter editor.
    enum columns
    {
        NAME = 0,
        DISPLAY_NAME,
        DESCRIPTION,
        TYPE,
        VALUE,
        CHOICE,
        MINIMUM,
        MAXIMUM,
        RESOLVE,
        BITWIDTH_LEFT,
        BITWIDTH_RIGHT,
        ARRAY_LEFT,
        ARRAY_RIGHT,
        USAGE_COUNT,
        ID,
        COLUMN_COUNT
    };
}
