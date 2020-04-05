# 4 Queen
  4 queen merupakan permasalahan untuk meletakkan 4 ratu pada papan catur berukuran 4x4 sedemikian hingga tidak ada ratu yang saling serang. Karena pada catur, ratu dapat menyerang secara diagonal, sebaris, dan sekolom, maka kita harus meletakkan ratu-ratu tersebut sedemikian hingga tidak ada ratu yang berada pada baris, kolom, dan diagonal yang sama. Kali ini diterapkan metode forward checking dengan memberi tanda pada sel yang jelas tidak bisa ditaruh oleh ratu lain atau merupakan sel tidak aman. Tidak ada input yang diperlukan, user hanya perlu menekan tombol enter untuk memunculkan solusi selanjutnya yang memungkinkan. File:
  - <a href ="https://github.com/rddmoon/AI4_CSP/blob/master/4-queen/4-queen.cpp">4-queen.cpp</a>
  
 # Penjelasan
 Pada awal kita deklarasikan papan catur 4x4 dengan array berukuran 4x4
 ```
 #define N 4

int board[N][N];
 ```
 Fungsi display merupakan fungsi untuk menampilkan hasil solusi yang telah ditemukan. Pada fungsi ini sel yang terdapat ratu diberi tanda '1' sementara sel kosong memiliki tanda '0'. Jika angka yang terdapat pada array sama dengan baris tempatnya berada maka dianggap queen diletakkan disitu.
 ```
void Display(){
	int i, j;
	printf("Solusi %d\n", solution);
	solution++;
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
			//printf("%d ", board[i][j]);
			//if row is the same with the mark then
			//that's where the queen placed
			if(board[i][j] == i){
				printf("1 ");
			}
			else{
				printf("0 ");
			}
		}
		printf("\n");
	}
}
 ```
 Fungsi Mark merupakan fungsi untuk melakukan forward checking, yaitu menandai semua baris, kolom, dan diagonal yang tidak aman jika kamu meletakkan ratu pada sel saat ini. Fungsi Mark menandai sel yang tidak aman dengan angka sesuai peletakan ratu pada tiap baris. Misalnya saat ini akan meletakkan ratu pada sel (2,3) maka fungsi Mark akan menandai sel tempat ratu diletakkan beserta semua sel yang tidak aman dengan angka '2'.
 ```
 void Mark(int row, int t, int initial, int mrow){
	int i;
	board[row][t] = mrow;
	for(i = row; i <= N; i++){
		//diagonal left
		if(t-(i-row) > 0){
			if(board[i][t-(i-row)] == initial){
				board[i][t-(i-row)] = mrow;
			}
		}
		//every column
		if(board[i][t] == initial){
			board[i][t] = mrow;
		}
		//diagonal right
		if(t+(i-row) < N+2){
			if(board[i][t+(i-row)] == initial){
				board[i][t+(i-row)] = mrow;
			}
		}
	}
}
 ```
 Fungsi Solve merupakan fungsi inti dalam mencari solusi dari 4 queen. Pada fungsi ini mencari di semua kemungkinan yang mungkin pada tiap sel pada board. Termasuk ketika ratu tidak dapat diletakkan pada sebuah baris karena sudah tidak ada sel yang aman (artinya kemungkinan solusi dari baris dan kolom sebelumnya sudah tidak ada), maka akan kembali ke baris sebelumnya untuk mencari di kolom selanjutnya.
 ```
 void Solve(int row){
	int i, j, k;
	if(row == N+1){
		Display();
		cin.get();
		return;
	}
	for(i = 1; i <= N; i++){
		if(board[row][i] == 0){
			Mark(row, i, 0, row);
			bool place = false;
			for(j = row + 1; j <= N; j++){
				place = true;
				for(k = 1; k <= N; k++){
					if(board[j][k]==0){
						place = false;
					}
				}
				if(place){ //if queen can't put in this row
					break;
				}
			}
			if(!place){ //if queen can be put in this row and column
				Solve(row+1);
			}
			Mark(row, i, row, 0);
		}
	}
}
 ```
 Fungsi main hanya berisi inisialisasi array board dan pemanggil fungsi Solver untuk mencari solusi dari 4 queen.
 ```
 int main(){
	//4-queen
	board[4][4]={0};
	Solve(1);
}
 ```
