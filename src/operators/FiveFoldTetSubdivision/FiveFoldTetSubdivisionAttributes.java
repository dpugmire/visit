// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

package llnl.visit.operators;

import llnl.visit.AttributeSubject;
import llnl.visit.CommunicationBuffer;
import llnl.visit.Plugin;
import java.lang.Integer;
import java.util.Vector;

// ****************************************************************************
// Class: FiveFoldTetSubdivisionAttributes
//
// Purpose:
//    Attributes for five fold tetrahedral subdivision operator
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

public class FiveFoldTetSubdivisionAttributes extends AttributeSubject implements Plugin
{
    private static int FiveFoldTetSubdivisionAttributes_numAdditionalAtts = 8;

    public FiveFoldTetSubdivisionAttributes()
    {
        super(FiveFoldTetSubdivisionAttributes_numAdditionalAtts);

        oddParityHasSixNeighborhood = true;
        addComponentInformation = false;
        idVar = new String("");
        valueVar = new String("");
        contourTreeFilename = new String("");
        isovalue = 0;
        selectedIds = new Vector();
        highlightedIds = new Vector();
    }

    public FiveFoldTetSubdivisionAttributes(int nMoreFields)
    {
        super(FiveFoldTetSubdivisionAttributes_numAdditionalAtts + nMoreFields);

        oddParityHasSixNeighborhood = true;
        addComponentInformation = false;
        idVar = new String("");
        valueVar = new String("");
        contourTreeFilename = new String("");
        isovalue = 0;
        selectedIds = new Vector();
        highlightedIds = new Vector();
    }

    public FiveFoldTetSubdivisionAttributes(FiveFoldTetSubdivisionAttributes obj)
    {
        super(obj);

        int i;

        oddParityHasSixNeighborhood = obj.oddParityHasSixNeighborhood;
        addComponentInformation = obj.addComponentInformation;
        idVar = new String(obj.idVar);
        valueVar = new String(obj.valueVar);
        contourTreeFilename = new String(obj.contourTreeFilename);
        isovalue = obj.isovalue;
        selectedIds = new Vector();
        for(i = 0; i < obj.selectedIds.size(); ++i)
        {
            Integer iv = (Integer)obj.selectedIds.elementAt(i);
            selectedIds.addElement(new Integer(iv.intValue()));
        }
        highlightedIds = new Vector();
        for(i = 0; i < obj.highlightedIds.size(); ++i)
        {
            Integer iv = (Integer)obj.highlightedIds.elementAt(i);
            highlightedIds.addElement(new Integer(iv.intValue()));
        }

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return FiveFoldTetSubdivisionAttributes_numAdditionalAtts;
    }

    public boolean equals(FiveFoldTetSubdivisionAttributes obj)
    {
        int i;

        // Compare the elements in the selectedIds vector.
        boolean selectedIds_equal = (obj.selectedIds.size() == selectedIds.size());
        for(i = 0; (i < selectedIds.size()) && selectedIds_equal; ++i)
        {
            // Make references to Integer from Object.
            Integer selectedIds1 = (Integer)selectedIds.elementAt(i);
            Integer selectedIds2 = (Integer)obj.selectedIds.elementAt(i);
            selectedIds_equal = selectedIds1.equals(selectedIds2);
        }
        // Compare the elements in the highlightedIds vector.
        boolean highlightedIds_equal = (obj.highlightedIds.size() == highlightedIds.size());
        for(i = 0; (i < highlightedIds.size()) && highlightedIds_equal; ++i)
        {
            // Make references to Integer from Object.
            Integer highlightedIds1 = (Integer)highlightedIds.elementAt(i);
            Integer highlightedIds2 = (Integer)obj.highlightedIds.elementAt(i);
            highlightedIds_equal = highlightedIds1.equals(highlightedIds2);
        }
        // Create the return value
        return ((oddParityHasSixNeighborhood == obj.oddParityHasSixNeighborhood) &&
                (addComponentInformation == obj.addComponentInformation) &&
                (idVar.equals(obj.idVar)) &&
                (valueVar.equals(obj.valueVar)) &&
                (contourTreeFilename.equals(obj.contourTreeFilename)) &&
                (isovalue == obj.isovalue) &&
                selectedIds_equal &&
                highlightedIds_equal);
    }

    public String GetName() { return "FiveFoldTetSubdivision"; }
    public String GetVersion() { return "1.0"; }

    // Property setting methods
    public void SetOddParityHasSixNeighborhood(boolean oddParityHasSixNeighborhood_)
    {
        oddParityHasSixNeighborhood = oddParityHasSixNeighborhood_;
        Select(0);
    }

    public void SetAddComponentInformation(boolean addComponentInformation_)
    {
        addComponentInformation = addComponentInformation_;
        Select(1);
    }

    public void SetIdVar(String idVar_)
    {
        idVar = idVar_;
        Select(2);
    }

    public void SetValueVar(String valueVar_)
    {
        valueVar = valueVar_;
        Select(3);
    }

    public void SetContourTreeFilename(String contourTreeFilename_)
    {
        contourTreeFilename = contourTreeFilename_;
        Select(4);
    }

    public void SetIsovalue(double isovalue_)
    {
        isovalue = isovalue_;
        Select(5);
    }

    public void SetSelectedIds(Vector selectedIds_)
    {
        selectedIds = selectedIds_;
        Select(6);
    }

    public void SetHighlightedIds(Vector highlightedIds_)
    {
        highlightedIds = highlightedIds_;
        Select(7);
    }

    // Property getting methods
    public boolean GetOddParityHasSixNeighborhood() { return oddParityHasSixNeighborhood; }
    public boolean GetAddComponentInformation() { return addComponentInformation; }
    public String  GetIdVar() { return idVar; }
    public String  GetValueVar() { return valueVar; }
    public String  GetContourTreeFilename() { return contourTreeFilename; }
    public double  GetIsovalue() { return isovalue; }
    public Vector  GetSelectedIds() { return selectedIds; }
    public Vector  GetHighlightedIds() { return highlightedIds; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteBool(oddParityHasSixNeighborhood);
        if(WriteSelect(1, buf))
            buf.WriteBool(addComponentInformation);
        if(WriteSelect(2, buf))
            buf.WriteString(idVar);
        if(WriteSelect(3, buf))
            buf.WriteString(valueVar);
        if(WriteSelect(4, buf))
            buf.WriteString(contourTreeFilename);
        if(WriteSelect(5, buf))
            buf.WriteDouble(isovalue);
        if(WriteSelect(6, buf))
            buf.WriteIntVector(selectedIds);
        if(WriteSelect(7, buf))
            buf.WriteIntVector(highlightedIds);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            SetOddParityHasSixNeighborhood(buf.ReadBool());
            break;
        case 1:
            SetAddComponentInformation(buf.ReadBool());
            break;
        case 2:
            SetIdVar(buf.ReadString());
            break;
        case 3:
            SetValueVar(buf.ReadString());
            break;
        case 4:
            SetContourTreeFilename(buf.ReadString());
            break;
        case 5:
            SetIsovalue(buf.ReadDouble());
            break;
        case 6:
            SetSelectedIds(buf.ReadIntVector());
            break;
        case 7:
            SetHighlightedIds(buf.ReadIntVector());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + boolToString("oddParityHasSixNeighborhood", oddParityHasSixNeighborhood, indent) + "\n";
        str = str + boolToString("addComponentInformation", addComponentInformation, indent) + "\n";
        str = str + stringToString("idVar", idVar, indent) + "\n";
        str = str + stringToString("valueVar", valueVar, indent) + "\n";
        str = str + stringToString("contourTreeFilename", contourTreeFilename, indent) + "\n";
        str = str + doubleToString("isovalue", isovalue, indent) + "\n";
        str = str + intVectorToString("selectedIds", selectedIds, indent) + "\n";
        str = str + intVectorToString("highlightedIds", highlightedIds, indent) + "\n";
        return str;
    }


    // Attributes
    private boolean oddParityHasSixNeighborhood;
    private boolean addComponentInformation;
    private String  idVar;
    private String  valueVar;
    private String  contourTreeFilename;
    private double  isovalue;
    private Vector  selectedIds; // vector of Integer objects
    private Vector  highlightedIds; // vector of Integer objects
}

