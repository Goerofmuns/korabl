#Work todo
This file is where I put all of the stuff I think of, so I don't forget it.

##Game

* **IMPORTANT** make topdown
* Implement a local coordinates system independent of window resolution
* Implement a modular system for panels
* remove the hardcoded aspects, make parts and ships more modular
* get texture manager to auto scan textures
* game heirarchy:
```
    Space
      |
      |
    Vessel
      |
      | <- Docking
      |
    Module
      |
      | <- Contains
      |
    Objects
```

### Vessel
The Vessel class encompasses any object floating in space. The vessel
consists of a tree structure of modules. A vessel has several properties:

* X and Y coords
* X and Y velocity
* Mass

On each game tick the vessels are moved based on their velocty.
Vessels should be serializable, in order for multiplayer to function.

### Module
The Module class is a single part of a vessel. It connects to other
Modules via docking ports, and shares power/air/resources. Multiple
connected Modules form a single Vessel. A module could be a Command Module, 
a Living Space, Computer Room, Engine Room, or more.

* Air Pressure
* Volume (m ^ 2)
* Internal and External Collider
* Hatches / States (Open / Closed / Moving)


The interior of each module is effectively a cylinder with varying widths.
Along the 

#### Module format
Modules can be specified in a file format. They are situated in a
folder structure as below:
```
modules/
\
 |
 Module A/
 | \
 |  |-module.json
 |  |-int_texture.png
 |  \-ext_texture.png
 |
 Module B/
   \
    |-module.json
    |-int_texture.png
    \-ext_texture.png
```  

Modules are specified in a JSON format. The format specifies
module external and internal size, air volume, and resource info.
Resources are either stored in Containers, or created by Generators.

**Interior Coordinates**
Modules have an internal coordinate system, roughly equivalent to metres.
Most modules have a height of 4, with narrows (docking tunnels etc) of 2.

An example module.json, for the TKS itself, is below.
```
{
    "name":"TKS",
    "description":"A VA capsule connected to a FGB, the TKS is a veritable Space Camper van.",
    "size":[10,4],
    "volume":45,

    "sections":
    {
        /* [width, height] */
        "docking port":[2, 2],
        "living space":[5, 4],
        "crew tunnel" :[1, 2],
        "cockpit"     :[2, 4]
    },

    "docking_nodes":
    {
        "rear_port":[0, 2]
    }
}        
```
##Computer
* integrate the CPU from [Astro](https://github.com/Goerofmuns/Astro)
* make a functional panel for control
* make a TTY, teletype or screen
* give CPU control over flight
* give CPU a user interface

##Flight
* Create an open space area, where ships can fly freely
* objects like asteroids and derelicts
* docking system between ships
* (maybe) orbital mechanics system
* (maybe, long term) multiple ships to choose from

##Art
* draw a soyuz or apollo

