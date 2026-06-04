# Welcome to Colosseum, a successor of [AirSim](https://github.com/microsoft/AirSim)
  
## Build Status
[![Ubuntu Build](https://github.com/CodexLabsLLC/Colosseum/actions/workflows/test_ubuntu.yml/badge.svg)](https://github.com/CodexLabsLLC/Colosseum/actions/workflows/test_ubuntu.yml)
[![MacOS Build](https://github.com/CodexLabsLLC/Colosseum/actions/workflows/test_macos.yml/badge.svg)](https://github.com/CodexLabsLLC/Colosseum/actions/workflows/test_macos.yml)
[![Windows Build](https://github.com/CodexLabsLLC/Colosseum/actions/workflows/test_windows.yml/badge.svg)](https://github.com/CodexLabsLLC/Colosseum/actions/workflows/test_windows.yml)

[![](https://dcbadge.vercel.app/api/server/y9ZJKKKn8J)](https://discord.gg/y9ZJKKKn8J)
  
  
## IMPORTANT ANNOUNCEMENT
Moving forward, we are now using Unreal Engine 5 version 5.03 or greater! If you
want to use UE4.27, you can use the branch `ue4.27`.
  
## Unreal Engine Version for Main Branch
The main branch of this repository **only** supports **Unreal Engine 5.6**! Please see our other branches
for other versions that we support.
  
## Currently Supported Operating Systems
Below are the list of officially supported Operating Systems, with full Unreal Engine support:
### Windows
- Windows 10 (Latest)

### Linux
- Ubuntu 20.04 (use branch `ubuntu-20.04`)
- Ubuntu 22.04
- Ubuntu 24.04
  
**NOTE** Ubuntu 22.04 is not currently supported due to Vulkan support. If this changes, we will notify you here. If you want to use Colosseum on 22.04, we highly recommend that you use Docker.

### MacOS (Experimental)
- MacOS Ventura (14)
- MacOS Monterey (13)
  
**NOTE** MacOS support is highly experimental and may be dropped in future releases. This is because Apple continually changes their build tools and doesn't like 3rd party developers in general. There are ongoing discussions to remove this support.

  
## Introduction
  
Colosseum is a simulator for robotic, autonomous systems, built on [Unreal Engine](https://www.unrealengine.com/) (we now also have an experimental [Unity](https://unity3d.com/) release). It is open-source, cross platform, and supports software-in-the-loop simulation with popular flight controllers such as PX4 & ArduPilot and hardware-in-loop with PX4 for physically and visually realistic simulations. It is developed as an Unreal plugin that can simply be dropped into any Unreal environment. Similarly, we have an experimental release for a Unity plugin.
  
This is a fork of the AirSim repository, which Microsoft decided to shutdown in July of 2022. This fork serves as a waypoint to building a new and better simulation platform.
  
## Docs
Please find the docs [here](https://codexlabsllc.github.io/Colosseum/)

## Join the Community
We have decided to create a Discord channel to better allow for community engagement. Join here: [Colosseum Robotics Discord](https://discord.gg/y9ZJKKKn8J).
  

## License

This project is released under the MIT License. Please review the [License file](LICENSE) for more details.


