# lynxengine

Simple light-weight 3D capable game engine.

When running on a headless server it must be run using a virtual frame buffer so that GLFW can initialise correctly.
This can be achieved using Xvfb.

Use of a program such as 'pngcheck -c [file]' is advised to ensure that all image assets pass CRC checks.

## dependencies

- GLFW3
- GLM
- GLAD (INCLUDED)
- LODEPNG (INCLUDED)

## progress

artefact  
- [x] file loading & saving
- [x] configuration loading
- [x] thread safe debug logging
- [x] timer and fps cap handling
- [x] basic window creation & management
- [x] user input capture : mouse & keyboard
- [x] shared threaded resource handler
- [x] resource loading : sprites
- [x] resource loading : shaders
- [x] resource loading : meshes
- [ ] resource loading : samples
- [x] resource creation : sprites
- [x] resource creation : render textures
- [ ] basic sprite rendering
- [ ] gui interaction
- [ ] text rendering
- [x] basic mesh rendering
- [x] mesh texture application
- [ ] mesh dynamic lighting
- [x] basic component-entity system
- [x] base components : transform, camera, mesh renderer
- [ ] camera compositing
- [ ] post-processing effects
- [ ] basic cuboid collision detection
- [ ] basic cuboid collision resolution
- [ ] complex convex shape collision detection
- [ ] complex convex shape collision resolution
- [ ] sample playback
- [ ] auditory world-space simulation
