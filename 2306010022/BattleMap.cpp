#include"DxLib.h"
#include"BattleMap.h"

void BattleMap::InitMap()
{
	LoadDivGraph("data/texture/map.png", 2, 2, 1, 64, 64,mapGraph);
	backgraph = LoadGraph("data/texture/back_1.png");
}


void BattleMap::DrawMap()
{
	//DrawGraph(0, 0, map.backgraph,true);

	for (int y = 0; y < 17; y++)
	{
		for (int x = 0; x <widthchipnum; x++)
		{
			if (g_MapChipList[y][x] == 1)
			{
				DrawGraph(x * 64, y * 64, mapGraph[1], TRUE);
			}
		}
	}
}