# StandLight_Clock_Stowatch_Temp_Distance (edit. 20220921)
라즈베리파이를 이용한 탁상용 스탠드 개발 코드
탁상용 스탠드 + 시계 + 온습도 + 사용자 거리 체크 + 선풍기
LED5개 조절 및 I2C LCD, DHT11, UltraSonic, DC Motor, MotorDriver 이용
1. 독서등(main 기능), 밝기 조절 [O]
2. 시계기능 - 한국시간 기준[O]
3. 스탑워치 [O] : 시계 -> 스탑워치 시작 -> 스탑워치 정지 -> 시계(스탑워치 리셋)
    스탑워치 일시정지 -> 시작 -> 일시정지 필요[X]
3. 온습도센서[O] + 30도 이상일 시 선풍기 동작 on / off [O]
4. 초음파센서 이용 사용자 부재시 LED, 선풍기 off [O]

# 소프트웨어 구조 설계 다이어그램

![image](https://user-images.githubusercontent.com/113006092/190934718-a1603bbe-ce73-4302-a95f-f1156059213f.png)