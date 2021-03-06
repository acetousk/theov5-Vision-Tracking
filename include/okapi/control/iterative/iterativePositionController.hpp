/**
 * @author Ryan Benasutti, WPI
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef _OKAPI_ITERATIVEPOSITIONCONTROLLER_HPP_
#define _OKAPI_ITERATIVEPOSITIONCONTROLLER_HPP_

#include "okapi/control/iterative/iterativeController.hpp"

namespace okapi {
class IterativePositionControllerArgs : public IterativeControllerArgs {};

class IterativePositionController : public IterativeController {};
} // namespace okapi

#endif
