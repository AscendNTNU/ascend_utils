# ascend_utils
Launch files, configuration and shared utility scripts

## Launchfiles
`drone.launch` serves as the launch file for starting nodes on a single drone. 

Launchfiles should both be written so that all that is needed to start up is running `roslaunch ascend_utils drone.launch`. They should also contain options for disabling nodes in an easy manner. See ![here](https://github.com/AscendNTNU/ascend_utilities/blob/master/launch/primary.launch) for an example from the 2017 drone. 

### mavlink_shell.py
For very simple commands, mavlink has a command line interface. This allows calibration without QGroundControl.

```
./mavlink_shell.py /dev/ttyPixhawk:921600
```
