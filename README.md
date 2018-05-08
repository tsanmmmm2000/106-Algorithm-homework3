# Activity Selection Problem
題目說明：

給定N個工作，每個工作由編號，開始時間，結束時間和產值構成。選出能最大化產值的工作集合且其時間不會有重疊的情形。

輸入:

第一行為一整數n，代表接下來會有n筆測試資料 (n <= 10)。每筆測試資料的第一行為一整數k(<=1000)，k代表接下來會有k行(表示該筆測資有k個activity)，每個activity由四個數字構成(皆為整數(正負數皆可能))，數字間用一個空白分開)，分別為activity的編號(number)、開始時間(start time>=0)、結束時間(finish time>0)、產值(value)。

輸出:

螢幕輸出。

每筆測資輸出兩行，

第一行: activity不衝突的情況下，value總和的最大值為多少，

第二行: 列出此最大化value的activity集合, 以activity的編號由小到大列出(每個activity編號間請用空白鍵隔開)。

Example：

input:

2

3

1 0 3 4

2 3 4 1

3 3 5 2

5

1 8 21 19

2 10 15 12

3 4 9 18

4 20 30 25

5 0 5 15

output:

6

1 3

55

2 3 4
