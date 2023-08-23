# filament-jupyter-tutorial-cpp

----------------------------
## 단기목표
filament cpp를 jupyter notebook에 띄우기

## INSTALL
#### Dependency

- [conda installation guide](https://docs.conda.io/projects/conda/en/latest/user-guide/install/index.html)

`conda` `xeus-cling` `jupyter` `notebook` `filament` <br>
The release version google filament is already included in the current repository. 
Because we depend on `xeus-cling`, the examples are only possible in the following platform, Linux, WSL.

```cmd
conda create -n oss xeus-cling -c conda-forge
pip3 install jupyter
```

@@TODO check whether none-dev version is possible or not
```cmd
sudo apt get install clang-12 libc++-12-dev libc++abi-12-dev libunwind-dev
```

## BUILD
xeus-cling은 shared library(.so) 파일만 임포트할 수 있습니다. 현재 repository에서 작성한 cmake 파일로 static library를 shared library로 변환해주어야만 합니다.

@@현재 CMAKE 작성된 파일 clang 기준, gcc 버전도 확인 필요
clang path 설정 후 확인
```cmd
export CC=$YOUR_CLANG12_PATH
export CXX=$YOUR_CLANG++12_PATH
```

```cmd
mkdir build
cd build
cmake ..
make
```

## RUN
jupyter notebook을 실행시킨 후 웹브라우저로 접속해 jupyter notebook 파일에 작성된 예제들을 실행, 변형시켜볼 수 있습니다.

```cmd
jupyter notebook
```

## 셋팅
3rd party 라이브러리를 임포트 하기 위한 예시 명령어는 다음과 같습니다.

```cxx
#pragma cling add_include_path("필라멘트 헤더 경로")
#pragma cling add_library_path("필라멘트 라이브러리 경로")
#pragma cling load("라이브러리 명칭")
```

## Reference
- [filament-github](https://github.com/google/filament)
- [filament-official-document](https://google.github.io/filament/)
- [xeus-cling reference](https://github.com/jupyter-xeus/xeus-cling)