#include<stdio.h>
#include<conio.h>
#define 작은열기 (
#define 는 =
#define 증가 ++
#define 감소 --
#define 끝 ;
#define 더하기 +
#define 빼기 -
#define 만약 if(
#define 작은닫기 )
#define 큰열기 {
#define 큰닫기 }
#define 같을까 ==
#define 오른쪽이큼 <
#define 왼쪽이큼 >
#define 반환 return
#define 정수 int
#define 아주큰열기 [
#define 아주큰닫기 ]
#define 창유지 _getch














정수 a 아주큰열기 100 아주큰닫기 끝
정수 tmp 끝


정수 main 작은열기 작은닫기
큰열기
정수 n 는 0 끝
scanf_s 작은열기 "%d", &n 작은닫기 끝
for (int i = 0; i 오른쪽이큼 n 끝 i 증가)
	큰열기
	scanf_s 작은열기 "%d", &a 아주큰열기 i 아주큰닫기 작은닫기 끝
	큰닫기

	for (int i = 0; i 오른쪽이큼 n 빼기 1 끝 i 증가)
		큰열기
		for 작은열기 int j = i + 1; j 오른쪽이큼 n 끝 j 증가 작은닫기
			큰열기
			if 작은열기 a 아주큰열기 i 아주큰닫기 왼쪽이큼 a 아주큰열기 j 아주큰닫기 작은닫기
			큰열기
				tmp 는 a 아주큰열기 i 아주큰닫기 끝
				a 아주큰열기 i 아주큰닫기 는 a 아주큰열기 j 아주큰닫기 끝
				a 아주큰열기 j 아주큰닫기 는 tmp 끝
			큰닫기
		큰닫기
큰닫기
for(int i=0;i 오른쪽이큼 n 끝 i 증가)
	printf 작은열기 "%d ",a 아주큰열기 i 아주큰닫기 작은닫기 끝
printf 작은열기 "\n" 작은닫기 끝
창유지 작은열기 작은닫기 끝
반환 0 끝
큰닫기