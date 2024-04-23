Cub3D - 3D Graphics Engine for Cuboid Worlds

Welcome to Cub3D, a project designed to render 3D environments based on cuboid worlds. This implementation offers a versatile and efficient solution for rendering immersive 3D scenes, making it an invaluable tool for game development and graphics programming within C programs.

**Project Overview**

	•	What does cub3d do? - cub3d is a 3D graphics engine that renders cuboid worlds from a given map file. It leverages raycasting techniques to simulate the perception of depth and create immersive visuals reminiscent of classic first-person shooter games.
	•	Key Features
    	•	Raycasting Rendering: cub3d utilizes raycasting algorithms to render 3D environments in real-time, providing a fast and efficient method for generating dynamic visuals.
    	•	Map Parsing: The implementation includes robust map parsing capabilities, allowing developers to define custom 3D environments through simple map files.
    	•	Texture Mapping: cub3d supports texture mapping, enabling the application of textures to walls and surfaces within the 3D world, enhancing visual fidelity.
    	•	User Interaction: Interactive controls are integrated to enable player movement and interaction within the rendered environment, providing an immersive gaming experience.
    	•	Error Handling: Robust error handling is integrated to provide informative messages in case of unexpected scenarios or map-related issues, ensuring smooth execution of the program.

**How to Compile Cub3D**

To compile the cub3d project, follow these straightforward steps:

	•	Clone the Repository:
    	•	git clone git@github.com:Bgarnn/cub3d.git
    	•	cd cub3d
	•	Compile the Project:
    	•	make: This will generate the executable file for the cub3d project.
	•	Run the Project:
    	•	./cub3D ./maps/demo.cub
	•	Clean the Build:
    	•	make clean: This removes the object files, leaving only the compiled executable.

