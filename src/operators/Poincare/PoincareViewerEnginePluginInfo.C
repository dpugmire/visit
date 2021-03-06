// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ****************************************************************************
//  File: PoincareViewerEnginePluginInfo.C
// ****************************************************************************

#include <PoincarePluginInfo.h>
#include <PoincareAttributes.h>

//
// Storage for static data elements.
//
PoincareAttributes *PoincareViewerEnginePluginInfo::clientAtts = NULL;
PoincareAttributes *PoincareViewerEnginePluginInfo::defaultAtts = NULL;

// ****************************************************************************
//  Method:  PoincareViewerEnginePluginInfo::InitializeGlobalObjects
//
//  Purpose:
//    Initialize the operator atts.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************
void
PoincareViewerEnginePluginInfo::InitializeGlobalObjects()
{
    if (PoincareViewerEnginePluginInfo::clientAtts == NULL)
    {
        PoincareViewerEnginePluginInfo::clientAtts  = new PoincareAttributes;
        PoincareViewerEnginePluginInfo::defaultAtts = new PoincareAttributes;
    }
}

// ****************************************************************************
//  Method: PoincareViewerEnginePluginInfo::GetClientAtts
//
//  Purpose:
//    Return a pointer to the viewer client attributes.
//
//  Returns:    A pointer to the viewer client attributes.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

AttributeSubject *
PoincareViewerEnginePluginInfo::GetClientAtts()
{
    return clientAtts;
}

// ****************************************************************************
//  Method: PoincareViewerEnginePluginInfo::GetDefaultAtts
//
//  Purpose:
//    Return a pointer to the viewer default attributes.
//
//  Returns:    A pointer to the viewer default attributes.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

AttributeSubject *
PoincareViewerEnginePluginInfo::GetDefaultAtts()
{
    return defaultAtts;
}

// ****************************************************************************
//  Method: PoincareViewerEnginePluginInfo::SetClientAtts
//
//  Purpose:
//    Set the viewer client attributes.
//
//  Arguments:
//    atts      A pointer to the new client attributes.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

void
PoincareViewerEnginePluginInfo::SetClientAtts(AttributeSubject *atts)
{
    *clientAtts = *(PoincareAttributes *)atts;
    clientAtts->Notify();
}

// ****************************************************************************
//  Method: PoincareViewerEnginePluginInfo::GetClientAtts
//
//  Purpose:
//    Get the viewer client attributes.
//
//  Arguments:
//    atts      A pointer to return the client default attributes in.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

void
PoincareViewerEnginePluginInfo::GetClientAtts(AttributeSubject *atts)
{
    *(PoincareAttributes *)atts = *clientAtts;
}

// ****************************************************************************
//  Method: PoincareViewerEnginePluginInfo::InitializeOperatorAtts
//
//  Purpose:
//    Initialize the operator attributes to the default attributes.
//
//  Arguments:
//    atts        The attribute subject to initialize.
//    plot        The viewer plot that owns the operator.
//    fromDefault True to initialize the attributes from the defaults. False
//                to initialize from the current attributes.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

void
PoincareViewerEnginePluginInfo::InitializeOperatorAtts(AttributeSubject *atts,
                                              const avtPlotMetaData &plot,
                                              const bool fromDefault)
{
    if (fromDefault)
        *(PoincareAttributes*)atts = *defaultAtts;
    else
        *(PoincareAttributes*)atts = *clientAtts;

    UpdateOperatorAtts(atts, plot);
}

// ****************************************************************************
//  Method: PoincareViewerEnginePluginInfo::UpdateOperatorAtts
//
//  Purpose:
//    Update the operator attributes when using operator expressions.
//
//  Arguments:
//    atts        The attribute subject to update.
//    plot        The viewer plot that owns the operator.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

void
PoincareViewerEnginePluginInfo::UpdateOperatorAtts(AttributeSubject *atts, const avtPlotMetaData &plot)
{
}

// ****************************************************************************
//  Method: PoincareViewerEnginePluginInfo::GetOperatorVarDescription
//
//  Purpose:
//    Return the operator variable description.
//
//  Arguments:
//    atts        The attribute subject to initialize.
//    plot        The viewer plot that owns the operator.
//
//  Programmer: Allen Sanderson
//  Creation:   19 August 2013
//
// ****************************************************************************

#include <avtPlotMetaData.h>
#include <cstring>

std::string
PoincareViewerEnginePluginInfo::GetOperatorVarDescription(AttributeSubject *atts,
                                                    const avtPlotMetaData &plot)
{
    PoincareAttributes *atts_in = (PoincareAttributes *)atts;

    const char *typeString[14] =
      { "None", "Safety Factor Q", "Safety Factor P",
        "Safety Factor Q != P", "Safety Factor P != Q",
        "Toroidal Windings", "Poloidal Windings Q", "Poloidal Windings P",
        "Fieldline Order", "Point Order","Plane Order",
        "Winding Group Order", "Winding Point Order",
        "Winding Point Order Modulo" };

    std::string var = plot.GetVariableName();

    if( strncmp(var.c_str(), "operators/Poincare/",
                strlen("operators/Poincare/")) == 0)
    {
      std::string justTheVar = var.substr(strlen("operators/Poincare/"));

      var = justTheVar;
    }

    var += std::string(" - ") +
        std::string(typeString[atts_in->GetDataValue()]);

    return var;
}

// ****************************************************************************
//  Method: PoincareViewerEnginePluginInfo::GetMenuName
//
//  Purpose:
//    Return a pointer to the name to use in the viewer menus.
//
//  Returns:    A pointer to the name to use in the viewer menus.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

const char *
PoincareViewerEnginePluginInfo::GetMenuName() const
{
    return "Poincare";
}

