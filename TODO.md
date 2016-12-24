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

