/*
#include<Gl/glut.h>
#include <cmath> 
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iterator>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <cctype>
#include <list>
#include <tuple>
#include <random>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <iostream>
#define ll long long
#define vl vector<ll>
#define pb push_back
#define endl '\n'
#define pf push_front
#define OO 1e18
#define dql deque<ll>
#define GO  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0)
#define tt int t;cin>>t
#define nn long long n;cin>>n
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v)  v.begin(), v.end()
#define allr(v) v.rbegin() , v.rend()
#define ld long double
#define prq priorty_queue
#define R return
#define C continue
#define print(a) for(int i=0;i<a.size();i++) cout<<a[i]<<" "; cout<<endl;
#define to_int(a) a-48
#define len(a,b) sqrtl((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))
#define nod(x) static_cast<int>(log10(x))+1
using namespace std;
class Drawer
{
public :
	void drawTriangle(int x) {
		//glPolygonMode(GL_FRONT, GL_LINE);
		glColor3f(0.2, 0.6, 0.8); // ·Ê‰ «·„À·À (√“—ﬁ ”„«ÊÌ)
		glBegin(GL_POLYGON);
		glVertex2f(x - 0.5f, x - 0.5f); // «·—√” «·√Ê· (√”›· Ì”«—)
		glVertex2f(x + 0.5f, x - 0.5f);  // «·—√” «·À«‰Ì (√”›· Ì„Ì‰)
		glVertex2f(x + 0.0f, x + 0.5f);   // «·—√” «·À«·À (√⁄·Ï)
		glEnd();
	}
	void drawSqure() {
		//glPolygonMode(GL_FRONT, GL_LINE);
		glColor3f(0.8, 0.2, 0.5); // ·Ê‰ «·„À·À (√“—ﬁ ”„«ÊÌ)
		glBegin(GL_POLYGON);
		glVertex2f(-0.5f, -0.5f); // «·—√” «·√Ê· (√”›· Ì”«—)
		glVertex2f(0.5f, -0.5f);  // «·—√” «·À«‰Ì (√”›· Ì„Ì‰)
		glVertex2f(0.5f, 0.5f);  // «·—«” «·—«»⁄ («⁄·Ï «·Ì„Ì‰
		glVertex2f(-0.5f, 0.5f);   // «·—√” «·À«·À (√⁄·Ï Ì”«—)
		glEnd();
	}
    void drawCircle(int position, float radius) {
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);

        const ld PI = acos(-1);
        ld angle = 0;
        int numSegments = 200000; // Reduce for better performance
        for (int i = 0; i < numSegments; i++) {
            angle += 2 * PI / numSegments;
            ld x = radius * cos(angle);
            ld y = radius * sin(angle);

            // Adjust position based on the "position" variable
            if(position%3==0)
                glVertex2f(x + ((position-1) % 3 ) , y + (position / 3) -1);
            else 
                glVertex2f(x + ((position - 1) % 3 ) , y + (position / 3));
        }

        glEnd();
    }

    void drawCross(int position) {
        
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        float offsetX, offsetY;
        if (position % 3==0) {
            offsetX = ((position - 1) % 3);
            offsetY = (position / 3) - 1;
        }
        else
        {
            offsetX = ((position - 1) % 3);
            offsetY = (position / 3);
        }
 

        // Diagonal 1
        glVertex2f(offsetX - 0.4, offsetY - 0.4);
        glVertex2f(offsetX + 0.4, offsetY + 0.4);

        // Diagonal 2
        glVertex2f(offsetX - 0.4, offsetY + 0.4);
        glVertex2f(offsetX + 0.4, offsetY - 0.4);

        glEnd();
    }
};
*/
