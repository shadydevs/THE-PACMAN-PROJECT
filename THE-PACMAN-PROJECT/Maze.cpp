#include  "Maze.h"
//x 19, y 21
Maze::Maze(string _BMF, string _TF, string _PF) {		//BMF bitmapfile, TF texture file, PF pellet file.

	tileT.loadFromFile(_TF);
	pelletT.loadFromFile(_PF);

	bitmapFile.open(_BMF);
	for (int i = 0; i < sizey; i++)
	{
		for (int j = 0; j < sizex; j++)
		{
			bitmapFile >> bitmap[i][j];
			if (bitmap[i][j] < 0)
			{
				mazeSprites[i][j].setTexture(tileT);
				mazeSprites[i][j].scale(0.75f, 0.75f);			//final size of tile is	37.5p
				mazeSprites[i][j].setPosition(j * 37.5f, i * 37.5f + (37.5f * 2.0f));
				//							      (size of tile)  (vertical offset from top of window by two tiles)
			}
			else if (bitmap[i][j] > 0)
			{
				if (bitmap[i][j] != 5) {

					mazeSprites[i][j].setTexture(pelletT);
					mazeSprites[i][j].scale(0.75f, 0.75f);			//final size of pellet is 15p
					mazeSprites[i][j].setPosition(j * 37.5 + (18.75f - 7.5f), i * 37.5 + (18.75f - 7.5) + (37.5f * 2.0f));
					//						(size of tile)|(offset of half tile then adjusting half a pellet to center it)|(vertical offset from top of window by two tiles)
				}
				if (bitmap[i][j] == 2)
				{
					mazeSprites[i][j].scale(1.25f, 1.25f);
					mazeSprites[i][j].setColor(Color::Red);
				}

			}
		}
	}

	//for (int i = 0; i < sizey; i++) {
	//	for (int j = 0; j < sizex; j++)
	//	{
	//		cout << bitmap[i][j];
	//		cout << " \t";
	//	}
	//	cout << endl;
	//}

}