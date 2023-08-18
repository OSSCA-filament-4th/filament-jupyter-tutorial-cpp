# filament-jupyter-tutorial-cpp

----------------------------
## 단기목표
filament cpp를 jupyter notebook에 띄우기

## INSTALL

### Only possible in Linux and OS X
#### dependency (currently)
`xeus-cling` `jupyter` `notebook`

##### conda
```cmd
conda create -n oss xeus-cling
pip3 install jupyter
```

## RUN
```cmd
jupyter notebook
```

## 셋팅
현재 xeus-cling .so shared library만 임포트할 수 있습니다.
3rd party 라이브러리를 임포트 하기 위한 예시 명령어는 다음과 같습니다.

```cxx
#pragma cling add_include_path("필라멘트 헤더 경로")
#pragma cling add_library_path("필라멘트 라이브러리 경로")
#pragma cling load("라이브러리 명칭")
```