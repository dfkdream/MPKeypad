# MPKeypad Firmware Project

## 구성
1. Pin map
2. 키패드 매트릭스 처리
3. 이벤트 큐 및 핸들러
   1. 키패드 이벤트
   2. 로터리 이벤트
   3. USB 이벤트
4. UI 프레임워크
   1. 컴포넌트 기반
   2. 패널 단위 내비게이션
      1. 키패드 패널
      2. 아날로그 인풋 뷰어 패널

## 1. Pin map
### Keypad

| Function | GPIO # | 
|:---------|:-------|
| Row 0    | 18     |
| Row 1    | 17     |
| Row 2    | 16     |
| Col 0    | 15     |
| Col 1    | 13     |
| Col 2    | 14     |
| Col 3    | 12     |

### SPI OLED

| Function | GPIO # |
|----------|--------|
| CLK      | 2      |
| MOSI     | 3      |
| RES      | 4      |
| DC       | 5      |
| CS       | 6      |

### Knob

| Function | GPIO # |
|----------|--------|
| OTA      | 20     |
| OTB      | 21     |
| OTS      | 22     |

## 키패드 매트릭스

| 0   | 1   | 2   | 3   |
|-----|-----|-----|-----|
| 4   | 5   | 6   | 7   |
| 8   | 9   | 10  | 11  |


## 이벤트 처리

## UI 프레임워크