//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef INTERFACEDISP_H
#define INTERFACEDISP_H

#include "InterfaceKernel.h"
#include "Receiver.h"

/**
 * Imposes the jump between the displacements variables
 */
class InterfaceDisp : public InterfaceKernel
{
public:
  InterfaceDisp(const InputParameters & parameters);

  static InputParameters validParams();

protected:
  virtual Real computeQpResidual(Moose::DGResidualType type) override;
  virtual Real computeQpJacobian(Moose::DGJacobianType type) override;

  const Real _penalty;
  const VariableValue & _jump;
  const unsigned int _component;
};

#endif // INTERFACEDISP_H
