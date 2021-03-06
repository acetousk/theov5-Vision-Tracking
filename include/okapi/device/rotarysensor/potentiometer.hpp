/**
 * @author Ryan Benasutti, WPI
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef _OKAPI_POTENTIOMETER_HPP_
#define _OKAPI_POTENTIOMETER_HPP_

#include "api.h"
#include "okapi/device/rotarysensor/rotarySensor.hpp"

namespace okapi {
class Potentiometer : public RotarySensor {
  public:
  Potentiometer(const std::uint8_t iport);

  virtual ~Potentiometer();

  /**
   * Get the current sensor value.
   *
   * @return the current sensor value, or ``PROS_ERR`` on a failure.
   */
  virtual std::int32_t get() const override;

  /**
   * Get the sensor value for use in a control loop. This method might be automatically called in
   * another thread by the controller.
   *
   * @return the current sensor value, or ``PROS_ERR`` on a failure.
   */
  virtual double controllerGet() override;

  protected:
  pros::ADIPotentiometer pot;
};
} // namespace okapi

#endif
