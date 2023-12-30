class Solution {
public:


int minDeletions(string s) {
    int arr [100003];

    for(int i =0 ;i <100003; i++)
    {
        arr[i] = 0;
    }

    for(int i = 0; i < s.length(); i++){
        arr[s[i]]++;
    }

    sort(arr , arr + 100003);

    int count = 0;
    int idx = 100003;
    while(idx >  2)
    {
        idx -=1;

        if(arr[idx-1] >= arr[idx])
        {
            if(arr[idx] == 0)
            {
                count += arr[idx - 1];
                arr[idx-1] = 0;
            }else{

            int x = arr[idx - 1] - arr[idx] + 1;
            arr[idx-1] = arr[idx-1] - x;
            count+=x;
            }
        }
    }
    return count;
}
};