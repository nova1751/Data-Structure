#include<iostream>
using namespace std;
int main(){
    int n;
    int a[100000 + 5];
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    int left = 0;
    int tmpLeft = 0;
    int right = n - 1;
    int max = 0;
    int tmpSum = 0;
    for (int i = 0; i < n;i++){
        tmpSum += a[i];
        if(tmpSum<0){
            tmpSum = 0;
            tmpLeft = i + 1;
        }else if (max<tmpSum)
        {
            max = tmpSum;
            left = tmpLeft;
            right = i;
        }

    }
    if(max>=0)
        cout << max << " " << a[left] << " " << a[right];
    else
        cout << 0 << " " << a[0] << " " << a[n - 1];
}