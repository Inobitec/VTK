/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkImageMagnify3d.cxx
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
#include "vtkImageMagnify3d.h"
#include "vtkImageCache.h"


//----------------------------------------------------------------------------
// Description:
// Constructor: Sets default filter to be identity.
vtkImageMagnify3d::vtkImageMagnify3d()
{
  // create the filter chain 
  this->Filter0 = new vtkImageMagnify1d;
  this->Filter1 = new vtkImageMagnify1d;
  this->Filter2 = new vtkImageMagnify1d;

  this->SetAxes3d(VTK_IMAGE_X_AXIS, VTK_IMAGE_Y_AXIS, VTK_IMAGE_Z_AXIS);
  this->SetMagnificationFactors(1, 1, 1);
}


//----------------------------------------------------------------------------
void vtkImageMagnify3d::SetMagnificationFactors(int f0, int f1, int f2)
{
  // Having my own copy simplifies the Get methods.
  this->MagnificationFactors[0] = f0;
  this->MagnificationFactors[1] = f1;
  this->MagnificationFactors[2] = f2;
  this->Modified();
  
  ((vtkImageMagnify1d *)(this->Filter0))->SetMagnificationFactor(f0);
  ((vtkImageMagnify1d *)(this->Filter1))->SetMagnificationFactor(f1);
  ((vtkImageMagnify1d *)(this->Filter2))->SetMagnificationFactor(f2);
}


//----------------------------------------------------------------------------
void vtkImageMagnify3d::SetInterpolate(int interpolate)
{
  this->Modified();
  
  ((vtkImageMagnify1d *)(this->Filter0))->SetInterpolate(interpolate);
  ((vtkImageMagnify1d *)(this->Filter1))->SetInterpolate(interpolate);
  ((vtkImageMagnify1d *)(this->Filter2))->SetInterpolate(interpolate);
}



//----------------------------------------------------------------------------
int vtkImageMagnify3d::GetInterpolate()
{
  // Assume filter1 has same interpolate value as filter0
  return ((vtkImageMagnify1d *)(this->Filter0))->GetInterpolate();
}












