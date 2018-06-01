#include "main.hpp"
#include "../../Include/Driver/DriverBaseControl.hpp"
#include "../../Include/Driver/DriverArmP.hpp"
#include "../../Include/Driver/DriverScreenDrawing.hpp"





void opcontrol() {

Task driverBaseTask(driverBaseControl, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "DriverBaseControl");
Task driverArmPTask(armP, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "ArmP");
Task driverVisionDrawingTask(screenDrawTask, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "VisionDrawing");

  while (true)
  {
    delay(20);


  }
}
