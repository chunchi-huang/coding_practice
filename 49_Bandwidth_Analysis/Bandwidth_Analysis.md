Video Screaming, print out the accumulated bandwidth by time

struct videoStream{
	int start;
	int duration;
	int bandwidth;
};

Input:
{1,2,10}
{1,8,20}
{0,2,10}
{2,1,20}
{3,5,15}
{7,1,40}

0   1   2   3   4   5   6   7   8 
    10  10
    20  20  20  20  20  20  20  20
10  10    
        20
            15  15  15  15  15
                            40
-----------------------------------
10  40  50  35  35  35  35  75  20

Output:
10 40 50 35 35 35 35 75 20