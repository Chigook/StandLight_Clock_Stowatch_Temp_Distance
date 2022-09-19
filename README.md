# StandLight_Clock_Stowatch_Temp_Distance
라즈베리파이를 이용한 탁상용 스탠드 개발 코드
탁상용 스탠드 + 시계 + 온습도 + 사용자 거리 체크 + 선풍기
LED5개 조절 및 I2C LCD, DHT11, UltraSonic, DC Motor, MotorDriver 이용

1. 독서등(main 기능), 밝기 조절 [O]
2. 시계기능 [O] + 스탑워치 [X]
3. 온습도센서[O] + 온도 27이상일 시 선풍기 동작 on / off [O]
4. 초음파센서 이용 사용자 부재시 LED, 선풍기 off [O]

# 소프트웨어 구조 설계 다이어그램

![image](https://user-images.githubusercontent.com/113006092/190934718-a1603bbe-ce73-4302-a95f-f1156059213f.png)