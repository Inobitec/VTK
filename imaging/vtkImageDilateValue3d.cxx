/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkImageDilateValue3d.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$
  Thanks:    Thanks to C. Charles Law who developed this class.

Copyright (c) 1993-1995 Ken Martin, Will Schroeder, Bill Lorensen.

This software is copyrighted by Ken Martin, Will Schroeder and Bill Lorensen.
The following terms apply to all files associated with the software unless
explicitly disclaimed in individual files. This copyright specifically does
not apply to the related textbook "The Visualization Toolkit" ISBN
013199837-4 published by Prentice Hall which is covered by its own copyright.

The authors hereby grant permission to use, copy, and distribute this
software and its documentation for any purpose, provided that existing
copyright notices are retained in all copies and that this notice is included
verbatim in any distributions. Additionally, the authors grant permission to
modify this software and its documentation for any purpose, provided that
such modifications are not distributed without the explicit consent of the
authors and that existing copyright notices are retained in all copies. Some
of the algorithms implemented by this software are patented, observe all
applicable patent law.

IN NO EVENT SHALL THE AUTHORS OR DISTRIBUTORS BE LIABLE TO ANY PARTY FOR
DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
OF THE USE OF THIS SOFTWARE, ITS DOCUMENTATION, OR ANY DERIVATIVES THEREOF,
EVEN IF THE AUTHORS HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

THE AUTHORS AND DISTRIBUTORS SPECIFICALLY DISCLAIM ANY WARRANTIES, INCLUDING,
BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE, AND NON-INFRINGEMENT.  THIS SOFTWARE IS PROVIDED ON AN
"AS IS" BASIS, AND THE AUTHORS AND DISTRIBUTORS HAVE NO OBLIGATION TO PROVIDE
MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.


=========================================================================*/
#include "vtkImageDilateValue3d.h"

//----------------------------------------------------------------------------
// Description:
// This method sets up the three 1d filters that perform the dilation
vtkImageDilateValue3d::vtkImageDilateValue3d()
{
  // create the filter chain 
  this->Filter0 = new vtkImageDilateValue1d;
  this->Filter1 = new vtkImageDilateValue1d;
  this->Filter2 = new vtkImageDilateValue1d;

  this->SetAxes3d(VTK_IMAGE_X_AXIS, VTK_IMAGE_Y_AXIS, VTK_IMAGE_Z_AXIS);
}


//----------------------------------------------------------------------------
// Description:
// This method sets the dimensions of the rectangular kernel.
void vtkImageDilateValue3d::SetKernelSize(int width,int height,int depth)
{
  ((vtkImageDilateValue1d *)
   (this->Filter0))->SetKernelSize(width);
  ((vtkImageDilateValue1d *)
   (this->Filter1))->SetKernelSize(height);
  ((vtkImageDilateValue1d *)
   (this->Filter2))->SetKernelSize(depth);

  this->Modified();
}

//----------------------------------------------------------------------------
// Description:
// This method sets value to dilate
void vtkImageDilateValue3d::SetValue(float value)
{
  ((vtkImageDilateValue1d *)
   (this->Filter0))->SetValue(value);
  ((vtkImageDilateValue1d *)
   (this->Filter1))->SetValue(value);
  ((vtkImageDilateValue1d *)
   (this->Filter2))->SetValue(value);

  this->Modified();
}
