/* A robot in a grid can only move right one cell or down one cell
* the goal is to get from the upper left cell to the lower right
* cell. Accomplish this first with recursion from the last cell, (r,c)
* and then implement it through dynamic programming.
*/
//Recursion
ArrayList<Point> getPath(boolean maze[][]) {
	if (maze == null || maze.length == 0) return nulll
	ArrayList<Point> path = new ArrayList<Point>();
	if (getPath(maze, maze.length - 1, maze[0].length - 1, path)) {
		return path;
	}
	return null;
}
boolean getPath(boolean maze[][], int row, int col, ArrayList<Point> path) {
	//If out of bounds or not available, return.
	if (col < 0 || row < 0 || !maze[row][col]) {
		return false;
	}
	boolean isAtOrigin = (row == 0) && (col == 0);
	
	//If there's a path from the start to here, add location
	if (isAtOrigin || getPath(maze, row, col-1, path) || getPath(maze, row - 1, col, path)) {
		Point p = new Point(row, col);
		path.add(p);
		return true;
	}
	return false;
}

//The issue with this approach is that it takes O(2^r+c) time

/* To fix this with dynamic programming, we can store all of the
* cells we've already visited and passing that HashSet along. This
* will take O(2^r+c) to O(rc) time.
*/
ArrayList<Point> getPath(boolean maze[][]) {
	if (maze == null || maze.length == 0) return null;
	ArrayList<Point> path = new ArrayList<Point>();
	HashSet<Point> failedPoints = new HashSet<Point>();
	if (getPath(maze, maze.length - 1, maze[0].length - 1, path, failedPoints)) {
		return path;
	}
	return null;
}

boolean getPath(boolean maze[][], int row, int col, ArrayList<Point> path, HashSet<Point> failedPoints) {
	//If out of bounds or not available, return
	if (col < 0 || row < 0 || !maze[row][col]) {
		return false;
	}
	
	Point p = new Point(row, col);
	
	//If we've already visited the cell, return
	if (failedPoints.contains(p)) {
		return false;
	}
	
	boolean isAtOrigin = (row == 0) && (col == 0);
	
	//If there's a path from start to current location, add location
	if (isAtOrigin || getPath(maze, row, col - 1, path, failedPoints) ||
	getPath(maze, row - 1, col, path, failedPoints)) {
		path.add(p);
		return true;
	}
	
	failedPoints.add(p); //Cache result
	return false;
}