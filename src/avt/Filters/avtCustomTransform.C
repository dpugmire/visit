// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                            avtCustomTransform.C                           //
// ************************************************************************* //


#include <avtCustomTransform.h>

#include <vtkMatrix4x4.h>


// ****************************************************************************
//  Method: avtCustomTransform constructor
//
//  Programmer: Hank Childs
//  Creation:   January 21, 2006
//
// ****************************************************************************

avtCustomTransform::avtCustomTransform(void)
{
    mat = vtkMatrix4x4::New();
}


// ****************************************************************************
//  Method: avtCustomTransform destructor
//
//  Programmer: Hank Childs
//  Creation:   January 21, 2006
//
// ****************************************************************************

avtCustomTransform::~avtCustomTransform(void)
{
    mat->Delete();
}


// ****************************************************************************
//  Method: avtCustomTransform::SetMatrix
//
//  Purpose:
//      Sets the transform to use.
//
//  Programmer: Hank Childs
//  Creation:   January 21, 2006
//
// ****************************************************************************

void
avtCustomTransform::SetMatrix(vtkMatrix4x4 *m)
{
    mat->DeepCopy(m);
}


