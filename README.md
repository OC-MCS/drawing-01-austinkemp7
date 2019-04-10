# drawing-01-austinkemp7
drawing-01-austinkemp7 created by GitHub Classroom   

Saving/loading doesn't work. The problem is here:   
		while (file.read(reinterpret_cast<char*>(&insideShape), sizeof(insideShape))); <======= semicolon ends the loop body here!!!   
			addShape(Vector2f(insideShape.x, insideShape.y), insideShape.shape, Color(insideShape.currentColor));

Doesn't show current status of drawing settings   
Grade: 40
