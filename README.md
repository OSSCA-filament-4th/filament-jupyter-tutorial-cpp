# filament-jupyter-tutorial-cpp

----------------------------
## 단기목표
filament.js를 jupyter notebook에 띄우기

## INSTALL

### Windows
#### dependency (currently)
`nodejs` `npm` `jupyter` [`ijavascript`](https://github.com/n-riesco/ijavascript#installation) 

##### conda
```cmd
conda install nodejs
pip3 install jupyter
npm install -g ijavascript
ijsinstall

npm install filament
```

### Ubuntu
##### apt-repo
```bash
sudo apt-get install nodejs npm jupyter
npm config set prefix $HOME
npm install -g ijavascript
ijsinstall
```

## RUN
### Windows
```cmd
ijsnotebook --notebook-dir./
```