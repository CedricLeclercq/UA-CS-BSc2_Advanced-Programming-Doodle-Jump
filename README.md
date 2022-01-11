# Advanced programming - Doodle jump
Cédric Leclercq - s0200563

cedric.leclercq@student.uantwerpen.be

### How to run

This project is made with the SFML library version 2.4 in c++ 14. This version should be installed before running the normal main target.
There are two targets available, the AdvancedProgrammingDoodleJumpLogic and the AdvancedProgrammingDoodleJump.
The first one should be able to build without the SFML library installed. The target CMake version is 3.10.2.

It is important to keep in mind that the working directory needs to be set to the project root. 
Otherwise, certain files will not be able to be found.

### Design patterns

This projects makes use of four design patterns:
- Observer
- Model View Controller (MVC)
- Singleton
- Abstract Factory method

### Doxygen note

Three classes in the doxygen output (PlayerTexManager, PlatformTexManager and BGTileTexManager) don't seem to have any 
documentation, but this documentation is present in the project itself and can be found in src/textureManagers/TextureManagers.h.


### Known bugs

- Bug where the rocket texture for the player shows a small
black line to its left +- half the length of the rocket. This however seems to be a bug of the SFML library
rather than the texture itself (the texture doesn't show said black line). Doesn't affect the gameplay.

### In short

Versions:
- SFML: 2.4
- CMake: 3.10.2
- C++: 14
