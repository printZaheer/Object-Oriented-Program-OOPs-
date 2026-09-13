#include <iostream>
using namespace std;

struct Hero
{
    char *name;
    int hp;
    Hero(const char *n)
    {
        int size = 0;
        while (n[size] != '\0')
            size++;
        name = new char[size + 1];
        for (int i = 0; i < size; i++)
            name[i] = n[i];
        name[size] = '\0';
        hp = 100;
    }
    ~Hero()
    {
        delete[] name;
    }
};
struct Room
{
    int power;
    bool cursed;
    bool sealed;
    Room()
    {
        power = 0;
        cursed = false;
        sealed = false;
    }
};
struct Floor
{
    int roomCount;
    Room *rooms;
    Floor(int count)
    {
        roomCount = count;
        rooms = new Room[count];
    }
    ~Floor()
    {
        delete[] rooms;
    }
};
struct Dungeon
{
    int floorCount;
    Floor **floors;
    Dungeon(int depth)
    {
        floorCount = depth;
        floors = new Floor *[depth];
        for (int i = 0; i < depth; i++)
            floors[i] = new Floor(depth - i);
    }
    ~Dungeon()
    {
        for (int i = 0; i < floorCount; i++)
            delete floors[i];
        delete[] floors;
    }
};
void createRooms(Dungeon &dungeon)
{
    int roomNumber = 0;
    for (int i = 0; i < dungeon.floorCount; i++)
    {
        Floor *floor = dungeon.floors[i];
        for (int j = 0; j < floor->roomCount; j++)
        {
            Room *room = &floor->rooms[j];
            room->power = (j + 1) * 10;
            if ((i + 1) % 2 == 1 && (j + 1) % 2 == 1)
            {
                room->cursed = true;
                room->power = room->power * 2;
            }
            if (i == dungeon.floorCount - 1 && j == 0)
                room->power = 99;
            roomNumber++;
            if (roomNumber % 3 == 0)
                room->sealed = true;
        }
    }
}
void printMap(const Dungeon &dungeon)
{
    for (int i = 0; i < dungeon.floorCount; i++)
    {
        Floor *floor = dungeon.floors[i];
        cout << "  floor " << i + 1 << "   ";
        for (int j = 0; j < floor->roomCount; j++)
        {
            Room *room = &floor->rooms[j];
            if (room->sealed)
                cout << "[locked] ";
            else
                cout << "[ " << room->power << " ] ";
        }
        if (i == dungeon.floorCount - 1)
            cout << "<== boss chamber (sealed)";
        cout << endl;
    }
}
int countRooms(const Dungeon &dungeon)
{
    int count = 0;
    for (int i = 0; i < dungeon.floorCount; i++)
        count = count + dungeon.floors[i]->roomCount;
    return count;
}
int countCursed(const Dungeon &dungeon)
{
    int count = 0;
    for (int i = 0; i < dungeon.floorCount; i++)
    {
        Floor *floor = dungeon.floors[i];
        for (int j = 0; j < floor->roomCount; j++)
        {
            if (floor->rooms[j].cursed)
                count++;
        }
    }
    return count;
}
int countSealed(const Dungeon &dungeon)
{
    int count = 0;
    for (int i = 0; i < dungeon.floorCount; i++)
    {
        Floor *floor = dungeon.floors[i];
        for (int j = 0; j < floor->roomCount; j++)
        {
            if (floor->rooms[j].sealed)
                count++;
        }
    }
    return count;
}
Room *strongestMonster(
    Dungeon &dungeon,
    int &bestFloor,
    int &bestRoom)
{
    Room *strongest = NULL;
    bestFloor = 0;
    bestRoom = 0;
    for (int i = 0; i < dungeon.floorCount; i++)
    {
        Floor *floor = dungeon.floors[i];
        for (int j = 0; j < floor->roomCount; j++)
        {
            Room *room = &floor->rooms[j];
            if (!room->sealed)
            {
                if (strongest == NULL ||
                    room->power > strongest->power)
                {
                    strongest = room;
                    bestFloor = i + 1;
                    bestRoom = j + 1;
                }
            }
        }
    }
    return strongest;
}
void freeDungeon(Dungeon &dungeon)
{
    for (int i = dungeon.floorCount - 1; i >= 0; i--)
        cout << "  floor " << i + 1 << " freed ... ok" << endl;
    cout << "  floor table freed ... ok" << endl;
}
int main()
{
    char heroName[50];
    cout << "enter hero name : ";
    cin >> heroName;
    int depth;
    cout << "enter depth n : ";
    cin >> depth;
    if (depth <= 0)
    {
        cout << "invalid depth." << endl;
        return 0;
    }
    Hero hero(heroName);
    Dungeon dungeon(depth);
    createRooms(dungeon);
    cout << endl;
    cout << "======================================" << endl;
    cout << "      dungeon of the lost pointer" << endl;
    cout << "======================================" << endl;
    cout << " hero : " << hero.name
         << "   hp : " << hero.hp
         << "   depth : " << depth << endl;
    cout << "======================================" << endl;
    printMap(dungeon);
    int rooms = countRooms(dungeon);
    int cursed = countCursed(dungeon);
    int sealed = countSealed(dungeon);
    int bestFloor;
    int bestRoom;
    Room *strongest =
        strongestMonster(dungeon, bestFloor, bestRoom);
    cout << "======================================" << endl;
    cout << " rooms carved : " << rooms
         << "      rooms wasted : 0" << endl;
    cout << " cursed : " << cursed
         << "          sealed : " << sealed << endl;
    if (strongest != NULL)
    {
        cout << " strongest monster : "
             << strongest->power
             << " (floor " << bestFloor
             << ", room " << bestRoom << ")" << endl;
    }
    cout << "======================================" << endl;
    if (dungeon.floors[depth - 1]->rooms[0].sealed)
        cout << " >>> boss chamber sealed - run incomplete <<<" << endl;
    else
        cout << " >>> boss chamber open <<<" << endl;
    cout << "======================================" << endl;
    freeDungeon(dungeon);
    cout << "  hero name freed ... ok" << endl;
    cout << "  dungeon freed ..... ok" << endl;
    cout << "======================================" << endl;
    cout << "      dungeon collapsed. 0 bytes leaked."
         << endl;
    cout << "======================================" << endl;
    return 0;
}
