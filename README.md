# ascend_utils
Launch files, configuration and shared utility scripts

## Launchfiles
`jetson.launch` serves as the launch file for starting nodes on a single drone. 
`offboard.launch` is the launch file for starting nodes on the offboard computer.

They should both be written so that all that is needed to start up is running `roslaunch ascend_utils jetson.launch` or `roslaunch ascend_utils offboard.launch`. They should also contain options for disabling nodes in an easy manner. See ![here](https://github.com/AscendNTNU/ascend_utilities/blob/master/launch/primary.launch) for an example from the 2017 drone. 
