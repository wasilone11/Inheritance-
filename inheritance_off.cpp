#include<iostream>
using namespace std;
class unit
{
public:
    virtual void life(int &round,int &enemy_health)
    {
    }
    int range;
    int health;
    int damage;
    int cost;
    int return_coin;
    int step_size;
    int round;

};
class Archer:public unit
{
public:
    Archer(int var)
    {
        health=100;
        step_size=25;
        range=50;
    }
    void life(int &round,int &enemy_health)
    {
        while(1)
        {
            if(health>0&&(100-step_size)<=range)
            {
                enemy_health-=25;
                cout<<"Round :"<<round<<endl;
                cout<<"Archer Health :"<<health<<endl;
                cout<<"Positioned at :"<<step_size<<endl;
                cout<<"Archer is shooting Advanced Arrow"<<endl;
                cout<<"Enemy Tower's Health :"<<enemy_health<<endl;
                cout<<"Enemy Tower is shooting Fire arrow"<<endl;
                health-=40;
                round++;
                step_size+=25;
            }
            else if(health>0)
            {
                cout<<"Round :"<<round<<endl;
                cout<<"Archer Health :"<<health<<endl;
                cout<<"Running at:"<<step_size<<endl;
                cout<<"Enemy Tower's Health:"<<enemy_health<<endl;
                cout<<"Enemy Tower is shooting Fire arrow"<<endl;
                health-=40;
                round++;
                step_size+=25;
            }
            else
            {
                cout<<"Round :"<<round<<endl;
                cout<<"Archer Health:"<<health<<" UNIT DIED !"<<endl;
                break;
            }
        }
    }
};

class AdvancedArcher:public unit
{
public:
    AdvancedArcher(int var)
    {
        step_size=30;
        range=50;
        health=120;
    }
    AdvancedArcher()
    {
        step_size=30;
        range=50;
        health=120;
    }
    void life(int &round,int &enemy_health)
    {
        while(1)
        {
            if(health>0&&(100-step_size)<=range)
            {
                enemy_health-=50;
                cout<<"Round :"<<round<<endl;
                cout<<"Advance Archer Health :"<<health<<endl;
                cout<<"Positioned at "<<step_size<<endl;
                cout<<"Advance Archer is shooting Improved Arrow "<<endl;
                cout<<"Enemy Tower's Health :"<<enemy_health<<endl;
                cout<<"Enemy Tower is shooting Fire arrow "<<endl;
                step_size+=25;
                round++;
                health-=40;
                if(step_size>100)
                    step_size=100;
            }
            else if(health>0)
            {
                cout<<"Round :"<<round<<endl;
                cout<<"Advance Archer Health :"<<health<<endl;
                cout<<"Riding horse"<<endl;
                cout<<"Positioned at :"<<step_size<<endl;
                cout<<"Enemy Tower's Health :"<<enemy_health<<endl;
                cout<<"Enemy Tower is shooting Fire arrow "<<endl;
                round++;
                step_size+=30;
                health-=40;
                if(step_size>100)
                    step_size=100;
            }
            else
            {
                cout<<"Round :"<<round<<endl;
                cout<<"Advance Archer Health :"<<health<<endl;
                cout<<"UNIT DIED !"<<endl;
                break;
            }
        }
    }
};

class Bowman:public unit
{
public:
    Bowman(int var)
    {
        health=60;
        step_size=0;
    }
    Bowman()
    {
        health=60;
        step_size=0;
    }
    void life(int &round,int &enemy_health)
    {
        while(1)
        {
            if(health>0)
            {
                enemy_health-=10;

                cout<<"Round :"<<round<<endl;
                cout<<"Bowman Health :"<<health<<endl;
                cout<<"Positioned at :"<<step_size<<endl;
                cout<<"Bowman is shooting Basic Arrow "<<endl;
                cout<<"Enemy Tower's Health : "<<enemy_health<<endl;
                cout<<"Enemy Tower is shooting Fire arrow "<<endl;
                round++;
                health-=40;
            }
            else
            {
                cout<<"Round :"<<round<<endl;
                cout<<"Bowman's Health :"<<health<<endl;
                cout<<"UNIT DIED !"<<endl;
                cout<<"It returns 40 coins !"<<endl;
                break;
            }
        }
    }
};
class AdvancedBowman:public unit
{
public:
    AdvancedBowman(int var)
    {
        health=85;
        step_size=0;
    }
    AdvancedBowman()
    {
        health=85;
        step_size=0;
    }
    void life(int &round,int &enemy_health)
    {
        while(1)
        {
            if(health>0)
            {
                enemy_health-=15;

                cout<<"round :"<<round<<endl;
                cout<<"Advanced Bowman Health :"<<health<<endl;
                cout<<"Positioned at :"<<step_size<<endl;
                cout<<"Advance Bowman is shooting Canon "<<endl;
                cout<<"Enemy Tower's Health : "<<enemy_health<<endl;
                cout<<"Enemy Tower is shooting Fire arrow "<<endl;
                round++;
                health-=40;
            }
            else
            {
                cout<<"Round :"<<round<<endl;
                cout<<"Advanced Bowman's Health :"<<health<<endl;
                cout<<"UNIT DIED !"<<endl;
                cout<<"It returns 60 coins !"<<endl;
                break;
            }
        }
    }
};

int main()
{
    unit *w;
    int choice,coins=1600;
    int round=1,l,enemy_health=300;
    while(1)
    {
        if(enemy_health<=0)
        {
            cout<<"YOU WON "<<endl;
            return 0;
        }
        if(coins<100)
        {
            cout<<"YOU LOST ";
            return 0;
        }
        cout<<"Coins Remaining :"<<coins<<endl;
        cout<<"Select an option :"<<endl;
        cout<<"1. Archer (Cost 150)"<<endl;
        cout<<"2. Advanced Archer (Cost 600)"<<endl;
        cout<<"3. Bowman (Cost 100)"<<endl;
        cout<<"4. Advanced Bowman (Cost 200)"<<endl;

        cin>>choice;
        switch(choice)
        {
        case 1:

            if(coins<=0)
            {
                cout<<"YOU LOST "<<endl;
                return 0;
            }
            else if(coins<150)
            {
                cout<<"YOU DON'T HAVE SUFFICIENT COINS , SELECT ANOTHER OPTION "<<endl;
                break;
            }
            else
            {
                w=new Archer(0);
                w->life(round,enemy_health);
                coins-=150;
                break;
            }
        case 2:
            if(coins<=0)
            {
                cout<<"YOU LOST ";
                return 0;
                break;
            }
            else if(coins<600)
            {
                cout<<"YOU DON'T HAVE SUFFICIENT COINS , SELECT ANOTHER OPTION "<<endl;
                break;
            }
            else
            {
                w = new AdvancedArcher;
                w->life(round,enemy_health);
                coins-=600;
                break;
            }
        case 3:
            if(coins<100)
            {
                cout<<"YOU LOST";
                return 0;
            }
            else
            {
                w =  new Bowman;
                w->life(round,enemy_health);
                coins-=100;
                coins+=40;
                break;

            }
        default :
            if(coins<100)
            {
                cout<<"YOU LOST";
                return 0;
            }
            else if(coins<200)
            {
                cout<<"YOU DON'T HAVE SUFFICIENT COINS , SELECT ANOTHER OPTION"<<endl;
                break;
            }
            else
            {
                w = new AdvancedBowman;
                w->life(round,enemy_health);
                coins-=200;
                coins+=60;
                break;
            }

        }
    }
}

