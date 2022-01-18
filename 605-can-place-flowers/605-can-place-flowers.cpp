class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int res=0,len=flowerbed.size();
        if(len==1&&flowerbed[0]==0){
            res++;
        }
        else
		{
            for(int i=0;i<len;i++)
			{
            if(flowerbed[i]==0){
                if(i==0||i==(len-1)){
                    if(i==0&&flowerbed[i+1]==0){
                        res++;
                    } else if(i==(len-1)&& flowerbed[len-2]==0){
                        res++;
                    }
                }
                else if(flowerbed[i-1]==0&&flowerbed[i+1]==0){
                    res++;
                } else{
                    i--;
                }
            }
            i++;
        }
        }
        return res>=n;
    }
};