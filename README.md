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
- [ ] non-static light count handling
- [x] basic component-entity system
- [ ] base components : transform
- [x] base components : camera
- [ ] base components : mesh renderer
- [ ] camera compositing
- [ ] post-processing buffer switch
- [ ] post-processing : light-key
- [ ] post-processing : blur
- [ ] post-processing : monochrome
- [ ] post-processing : bloom
- [ ] post-processing : colour-grading
- [ ] basic cube collision detection
- [ ] basic cube collision resolution
- [ ] complex convex shape collision detection
- [ ] complex convex shape collision resolution
- [ ] sample playback
- [ ] auditory world-space simulation
- [ ] animation playback

## bugs

\> rotation is broken - replace vector rotation with quaternions
\> mesh renderer implementation is unoptimised - create renderqueue with automatic ordering
\> camera renders straight to default framebuffer - implement target framebuffers and basic compositing