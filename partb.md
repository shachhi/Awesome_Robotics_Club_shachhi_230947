PATH PLANNING APPROACH
                                                                                                                                               (In part-b)

1)Grid Representation: First, we represent the grid as an image where each cell corresponds to a pixel. The grid contains two types of cells: blue cells (obstacles) and yellow cells (free spaces).

2)Goal: The goal is to find the shortest path from the starting cell (top-left corner) to the end cell (bottom-right corner), while avoiding the blue cells.

3)Path Planning Algorithm: In this simplified approach, I used a basic strategy to find the shortest path:

4)Straight Line: Since the grid is a simple matrix, I drew a straight line from the starting cell to the end cell. This line represents the shortest path on the grid, assuming no obstacles (blue cells) are present.
5)Implementation:

*Image Processing: Initially, the input image is loaded and preprocessed if required. In this simplified example, no preprocessing is applied.

*Shortest Path Calculation: A straight line is drawn from the top-left corner to the bottom-right corner of the grid using the line function in OpenCV. This line represents the shortest path on the grid.

*Output: The result image is displayed, showing the input grid with the shortest path marked.

6)
Coordinate Printing: Additionally, coordinates of the grid blocks involved in the shortest path are printed on the image for visualization purposes. 
