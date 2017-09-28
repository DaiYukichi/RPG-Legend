//
//  main.c
//  RPG-Legend
//
//  Created by Mario De Roux on 09/26/17.
//  Copyright © 2017 Mario De Roux. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

struct CharacterClass {
    int Character_Class_id;
    char name[10];
    char dcp[250];
    int BDmg;
    int BDef;
    int BMdmg;
    int BMdef;
    int BAcc;
    int BEv;
    int BHp;
    int BMp;
};

struct PlayerStatus {
    char name[15];
    int lvl;
    int exp;
    int mexp;
    int stsp;
    int vit;
    int str;
    int dex;
    int intl;
    int luck;
};

struct CharacterStatus {
    int Hp;
    int Mp;
    int Atk;
    int Def;
    int MAtk;
    int MDef;
    int Acc;
    int Ev;
    int Critp;
    int CritDmg;
};

struct CharacterEquipment {
    char type[10];
    char name[25];
    char dscp[250];
    int hp;
    int mp;
    int pdmg;
    int mdmg;
    int pdef;
    int mdef;
    int acc;
    int ev;
};

struct Items {
    char name[10];
    char dscp[250];
    int itm_id;
};

struct Weapons{
    char name[30];
    char dscp[250];
    char type[10];
    int phdmg;
    int mdmg;
    int acc;
    int wep_id;
};

struct Enemies{
    char type[20];
    char name[25];
    int lvl;
    int hp;
    int mp;
    int atk;
    int def;
    int matk;
    int mdef;
    int acc;
    int ev;
    int critp;
    int critdmg;
    int gvnexp;
};

struct Inventory{
    int slotn;
    char itm_name[25];
    char itm_dscp[100];
    int itm_qty;
};


void printClass( struct CharacterClass character_class );
void printPlayerStatus ( struct PlayerStatus player);
void Menu();
void Sewer_drps();
void printPlayerEquipment (struct CharacterEquipment equipment);

int main()
{
    //Classes Declaration//
    struct CharacterClass Warrior;
    struct CharacterClass Mage;
    struct CharacterClass Archer;
    //Player Data Declaration//
    struct PlayerStatus Player;
    struct CharacterStatus Character;
    //Equipment Declaration//
    struct CharacterEquipment Helmet;
    struct CharacterEquipment Plate;
    struct CharacterEquipment Legs;
    struct CharacterEquipment Footwear;
    struct CharacterEquipment Weapon;
    //Items Declaration//
    struct Items Potion;
    //Weapons Declaration//
    struct Weapons BronzeSword;
    //Inventory Declaration//
    struct Inventory slot1;
    //Enemies Declaration//
    struct Enemies Goblin;
    
    //Classes Definittion Start//
    strcpy( Warrior.name, "Warrior");
    strcpy( Warrior.dcp, "A melee fighter whit high defense.");
    Warrior.BDmg=60;
    Warrior.BDef=120;
    Warrior.BMdmg=15;
    Warrior.BMdef=40;
    Warrior.BAcc=50;
    Warrior.BEv=50;
    Warrior.BHp=150;
    Warrior.BMp=50;
    Warrior.Character_Class_id=00001;
    strcpy( Mage.name, "Mage");
    strcpy( Mage.dcp, "A inteligent scholar who uses his magical\npowers wisely.");
    Mage.BDmg=20;
    Mage.BDef=30;
    Mage.BMdmg=110;
    Mage.BMdef=150;
    Mage.BAcc=10;
    Mage.BEv=10;
    Mage.BHp=50;
    Mage.BMp=150;
    Mage.Character_Class_id=00002;
    strcpy( Archer.name, "Archer");
    strcpy( Archer.dcp, "A ranged figther whit high accuracy, evasion\nand damage but can be taken down easy.");
    Archer.BDmg=100;
    Archer.BDef=50;
    Archer.BMdmg=45;
    Archer.BMdef=75;
    Archer.BAcc=100;
    Archer.BEv=100;
    Archer.BHp=75;
    Archer.BMp=60;
    Archer.Character_Class_id=00003;
    //Classes Definition End//
    //Equipment Start//
    strcpy(Weapon.name, "Not Equipped");
    Weapon.pdmg=0;
    Weapon.mdmg=0;
    Weapon.acc=0;
    strcpy(Helmet.type, "Helmet");
    strcpy(Helmet.name,"Not Equipped");
    Helmet.hp=0;
    Helmet.mp=0;
    Helmet.pdef=0;
    Helmet.mdef=0;
    Helmet.ev=0;
    strcpy(Plate.type, "Plate");
    strcpy(Plate.name,"Not Equipped");
    Plate.hp=0;
    Plate.mp=0;
    Plate.pdef=0;
    Plate.mdef=0;
    Plate.ev=0;
    strcpy(Legs.type, "Legs");
    strcpy(Legs.name,"Not Equipped");
    Legs.hp=0;
    Legs.mp=0;
    Legs.pdef=0;
    Legs.mdef=0;
    Legs.ev=0;
    strcpy(Footwear.type, "Footwear");
    strcpy(Footwear.name,"Not Equipped");
    Footwear.hp=0;
    Footwear.mp=0;
    Footwear.pdef=0;
    Footwear.mdef=0;
    Footwear.ev=0;
    //Equipment Definition End//
    //Items Definittion Start//
    strcpy(Potion.name, "Potion");
    strcpy(Potion.dscp, "Restores 50 Health");
    Potion.itm_id=10001;
    //Items Definition End//
    //Weapons Definition Start//
    strcpy(BronzeSword.name,"Bronze Sword");
    strcpy(BronzeSword.dscp,"A normal sword wielded by hunters");
    strcpy(BronzeSword.type,"Weapon");
    BronzeSword.phdmg=45;
    BronzeSword.mdmg=0;
    BronzeSword.acc=55;
    BronzeSword.wep_id=20001;
    //Weapons Definition End//
    //Inventory Definition Start//
    slot1.slotn=1;
    slot1.itm_qty=0;
    //Inventory Definition End//
    //Enemies Definition Start//
    strcpy(Goblin.type,"Goblin");
    strcpy(Goblin.name,"Goblin");
    Goblin.hp=200;
    Goblin.mp=100;
    Goblin.atk=75;
    Goblin.def=50;
    Goblin.matk=60;
    Goblin.mdef=40;
    Goblin.acc=45;
    Goblin.ev=30;
    Goblin.critp=3;
    Goblin.critdmg=(Goblin.atk*(float)((rand() %5 + 2)/2));
    Goblin.gvnexp=50;
    //Enemies Definition End//
    
    srand((unsigned)time(NULL));
    while (true)
    {
        int e;
        printf("%20s","Menu\n");
        printf("%15s","1-New Game\n");
        printf("%14s","2-Options\n");
        printf("%11s","3-Exit\n");
        scanf("%d",&e);
        switch(e)
        {
            case 1:
                system("clear");
                char pname[15];
                printf("%35s","Select Your Class\n\n");
                printClass(Warrior);
                printf("\n");
                printClass(Mage);
                printf("\n");
                printClass(Archer);
                printf("\n");
                scanf("%d",&e);
                switch(e)
                {
                case 1:
                        printf("\nIntroduce your player Name\n");
                        scanf("%s",pname);
                        //Player Stats Definition//
                        strcpy(Player.name, pname);
                        Player.lvl=1;
                        Player.exp=0;
                        Player.mexp=((Player.lvl*50)/2);
                        Player.stsp=0;
                        Player.vit=5;
                        Player.str=5;
                        Player.dex=3;
                        Player.intl=3;
                        Character.Hp=(Player.vit*Warrior.BHp);
                        Character.Mp=(Player.intl*Warrior.BMp);
                        Character.Atk=(Player.str*Warrior.BDmg);
                        Character.Def=(Player.vit*Warrior.BDef);
                        Character.MAtk=(Player.intl*Warrior.BMdmg);
                        Character.MDef=(Player.intl*Warrior.BMdef);
                        Character.Acc=(Player.dex*Warrior.BAcc);
                        Character.Ev=(Player.dex*Warrior.BEv);
                        Character.Critp=trunc(Player.dex/(float)(1/3));
                        Character.CritDmg=(Character.Atk*(float)((rand() %5 + 2)/2));
                        //Equipment//
                        strcpy(Weapon.type, BronzeSword.type);
                        strcpy(Weapon.name, BronzeSword.name);
                        strcpy(Weapon.dscp, BronzeSword.dscp);
                        Weapon.pdmg=BronzeSword.phdmg;
                        Weapon.mdmg=BronzeSword.mdmg;
                        Weapon.acc=BronzeSword.acc;
                        
                        goto GameStart;
                        
                case 2:
                        printf("\nIntroduce your player Name\n");
                        scanf("%s",pname);
                        //Player Stats Definition//
                        strcpy(Player.name, pname);
                        Player.lvl=1;
                        Player.exp=0;
                        Player.mexp=((Player.lvl*50)/2);
                        Player.stsp=0;
                        Player.vit=3;
                        Player.str=3;
                        Player.dex=3;
                        Player.intl=10;
                        Character.Hp=(Player.vit*Mage.BHp);
                        Character.Mp=(Player.intl*Mage.BMp);
                        Character.Atk=(Player.str*Mage.BDmg);
                        Character.Def=(Player.vit*Mage.BDef);
                        Character.MAtk=(Player.intl*Mage.BMdmg);
                        Character.MDef=(Player.intl*Mage.BMdef);
                        Character.Acc=(Player.dex*Mage.BAcc);
                        Character.Ev=(Player.dex*Mage.BEv);
                        Character.Critp=trunc(Player.dex/(float)(1/3));
                        Character.CritDmg=(Character.Atk*(float)((rand() %5 + 2)/2));
                        goto GameStart;
                    
                case 3:
                        printf("\nIntroduce your player Name\n");
                        scanf("%s",pname);
                        //Player Stats Definition//
                        strcpy(Player.name, pname);
                        Player.lvl=1;
                        Player.exp=0;
                        Player.mexp=((Player.lvl*50)/2);
                        Player.stsp=0;
                        Player.vit=3;
                        Player.str=5;
                        Player.dex=5;
                        Player.intl=3;
                        Character.Hp=(Player.vit*Archer.BHp);
                        Character.Mp=(Player.intl*Archer.BMp);
                        Character.Atk=(Player.str*Archer.BDmg);
                        Character.Def=(Player.vit*Archer.BDef);
                        Character.MAtk=(Player.intl*Archer.BMdmg);
                        Character.MDef=(Player.intl*Archer.BMdef);
                        Character.Acc=(Player.dex*Archer.BAcc);
                        Character.Ev=(Player.dex*Archer.BEv);
                        Character.Critp=trunc(Player.dex/(float)(1/3));
                        Character.CritDmg=(Character.Atk*(float)((rand() %5 + 2)/2));
                        goto GameStart;
                        
                }
        }
    GameStart:
        system("clear");
        printf("You wake up in a cell\n");
    Election:
        printf("What will you do?:\n");
        printf("1- Search the cell\n");
        printf("2- Wait for some time\n");
        printf("3- Ask if someone is there\n\n");
        scanf("%d",&e);
        switch(e)
        {
            case 1:
                printf("You find a hole under the bed and get into it\n");
                system( "read -n 1 -s -p \"Press any key to continue...\"" );
                goto TheSewer;
            
            case 2:
                printf("You wait for sometime until the guards get to your cell\n");
                
            case 3:
                printf("Nothing Happens.\n\n");
                goto Election;
        }
    
     TheSewer:
        system("clear");
        printf("%35s","You reach the sewer\n");
        printf("\nThe Sewer is like a maze, make the correct movements and you will reach the end\nelse you will reach the start back again\n");
        printf("\nHint: You can find items while you walk in any dungeon\n");
        bool exit=false;int frnt=0, lft=0, rgt=0, exf=rand()%10, exr=rand()%10, exl=rand()%10;
        while (exit!=true)
        {
        Sewer:
            printf("What will you do?:\n");
            printf("1-Walk to front\n2-Turn right\n3-Turn left\n4-Menu\n");
            scanf("%d",&e);
            switch(e)
            {
                case 1:
                    if ((rand()%100)<25)
                    {
                        Sewer_drps(Potion, slot1);
                    }
                    else if ((rand()%100)<60)
                    {
                        
                    }
                    printf("You walk front\n");
                    break;
                case 4:
                    while(true)
                    {
                        system("clear");
                        printf("\n%25s","Menu\n");
                        printf("1- Equiptment\n");
                        printf("2- Status\n");
                        printf("3- Inverntory\n");
                        printf("4- Exit\n");
                        scanf("%d",&e);
                        switch(e)
                        {
                            case 1:
                                system("clear");
                                printPlayerEquipment(Weapon);
                                printPlayerEquipment(Helmet);
                                printPlayerEquipment(Plate);
                                printPlayerEquipment(Legs);
                                printPlayerEquipment(Footwear);
                                system( "read -n 1 -s -p \"Press any key to continue...\"" );
                                break;
                            case 4:
                                system("clear");
                                goto Sewer;
                        }
                    }
                }
            }
        }
}

void printClass( struct CharacterClass character_class ) {
    
    printf( "Class name: %s\n", character_class.name);
    printf( "Class Description: %s\n", character_class.dcp);
}

void printPlayerStatus ( struct PlayerStatus player)
{
    printf("Player: %s\n", player.name);
}

void printPlayerEquipment (struct CharacterEquipment equipment)
{
    if(strcmp(equipment.type, "Weapon")==0)
    {
        printf("%s\n",equipment.name);
        printf("Type: %s\n",equipment.type);
        printf("Atack Damage: %d\n",equipment.pdmg);
        printf("Magic Damage: %d\n",equipment.mdmg);
        printf("Accuracy: %d\n\n",equipment.acc);
    }
    else{
        printf("%s\n",equipment.name);
        printf("Type: %s\n",equipment.type);
        printf("Heatlh Points: %d\n",equipment.hp);
        printf("Mana Points: %d\n",equipment.mp);
        printf("Physical Defense: %d\n",equipment.pdef);
        printf("Magic Defense: %d\n",equipment.mdef);
        printf("Evasion: %d\n\n",equipment.ev);
    }
}

void  Sewer_drps(struct Items potion, struct Inventory *slot1)
{
    printf("\nYou got a potion\n");
    strcpy(slot1->itm_name,potion.name);
    strcpy(slot1->itm_dscp,potion.dscp);
    slot1->itm_qty=slot1->itm_qty+1;
}
