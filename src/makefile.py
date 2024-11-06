"""
gcc -Wall -O2 -std=c99 -lraylib -lGL -lm -lpthread -lrt -lX11 -c main.c -o ofiles/main.o 
gcc -Wall -O2 -std=c99 -lraylib -lGL -lm -lpthread -lrt -lX11 -c modules/camera.c -o ofiles/camera.o
gcc -Wall -O2 -std=c99 -lraylib -lGL -lm -lpthread -lrt -lX11 -c modules/collision.c -o ofiles/collision.o
gcc -Wall -O2 -std=c99 -lraylib -lGL -lm -lpthread -lrt -lX11 -c modules/model.c -o ofiles/model.o

gcc -Wall -O2 -std=c99 -lraylib -lGL -lm -lpthread -lrt -lX11 ofiles/main.o ofiles/camera.o ofiles/collision.o ofiles/model.o -o build/Finish
"""

import os


class Compiler:
    def __init__(self, 
                 buildName = "gcRun", 
                 CModulesDirName = "modules", 
                 OFilesDirName = "ofiles", 
                 BuildDirName = "build", 
                 Cflags = "-Wall -O2 -std=gnu99 -lraylib -lGL -lm -lpthread -lrt -lX11") -> None:

        self.DefaultPath = os.path.dirname(os.path.abspath(__file__))
        print(f"-| Default Compiler File Path: {self.DefaultPath}")
        print("-"*150, " \n")

        # default dir names
        self.ModulesDir = CModulesDirName
        self.OfilesDir  = OFilesDirName
        self.buildDir   = BuildDirName
        self.buildName  = buildName
        self.CFlags     = Cflags

        # default dir path
        self.PathModulesDir = ""
        self.PathOFilesDir  = ""
        self.PathBuildDir   = ""

        if os.path.exists(f"{self.DefaultPath}/{self.ModulesDir}"):
            if os.path.exists(f"{self.DefaultPath}/{self.OfilesDir}"):
                if os.path.exists(f"{self.DefaultPath}/{self.buildDir}"):
                    self.PathModulesDir = f"{self.DefaultPath}/{self.ModulesDir}"
                    self.PathOFilesDir  = f"{self.DefaultPath}/{self.OfilesDir}"
                    self.PathBuildDir   = f"{self.DefaultPath}/{self.buildDir}"
                    self.AllOFileList   = []

                    print("Old .o Files Delete Process")
                    print("-"*150)
                    if os.listdir(f"{self.PathOFilesDir}") != []:
                        _AllOFilesHere = os.listdir(self.PathOFilesDir)
                        for i in _AllOFilesHere:
                            if os.path.exists(f"{self.PathOFilesDir}/{i}"):
                                os.remove(f"{self.PathOFilesDir}/{i}")
                                print(f":-| {self.PathOFilesDir}/{i} -> Old .o File Deleted")
                    print("-"*150, "\n")


                    print(f"Paths Is Ready | {self.PathModulesDir} | {self.PathOFilesDir} | {self.PathBuildDir} | \n")
                    print("-"*150)
                    print(f"C Files Tree :-| {self.PathModulesDir}")
                    self.ModuleCompileReady = []
                    for i in os.listdir(self.PathModulesDir):
                        if i.endswith(".c"):
                            if i not in self.ModuleCompileReady:
                                print(f"-:| C Modules- {i}")
                                self.ModuleCompileReady.append(f"{i}")
                    print("-"*150, "\n")


                    print("First Linking Process")
                    print("-"*150)
                    os.system(f"gcc {self.CFlags} -c {self.DefaultPath}/main.c -o {self.PathOFilesDir}/main.o")
                    print(f"gcc {self.CFlags} -c {self.DefaultPath}/main.c -o {self.PathOFilesDir}/main.o -> Finish")
                    for i in self.ModuleCompileReady:
                        _GCC = f"gcc {self.CFlags}"
                        _CFile = f"-c {self.PathModulesDir}/{i}"
                        _Output = f"-o {self.PathOFilesDir}/{i[:-2]}.o"
                        _Progress = f"{_GCC} {_CFile} {_Output}"
                        os.system(_Progress)
                        print(f"{_Progress} -> Finish")
                        self.AllOFileList.append(f"{self.PathOFilesDir}/{i[:-2]}.o")


                    _OFilesLongString = " ".join(self.AllOFileList)
                    if os.path.exists(f"{self.PathOFilesDir}/main.o"):
                        _GCC = f"gcc {self.CFlags}"
                        _MainOFile = f"{self.PathOFilesDir}/main.o "
                        _Output = f"-o {self.PathBuildDir}/{self.buildName}"
                        _Progress = f"{_GCC} {_MainOFile} {_OFilesLongString} {_Output}"
                        os.system(_Progress)
                        print(_Progress)
                    print("Compile is Finish!")
                    print("-"*150, " \n")


                    print(f".O Files Tree :| {self.PathOFilesDir}")
                    _OFileDirFiles = os.listdir(self.OfilesDir)
                    print("-"*150)
                    for i in _OFileDirFiles:
                        print(f":-| {i}")
                    print("-"*150, " \n")


                    print(f"Build Files Tree :-| {self.PathBuildDir}")
                    print("-"*150)
                    _BuildDirFiles = os.listdir(self.PathBuildDir)
                    for i in _BuildDirFiles:
                        print(f":-| {i}")
                    print("-"*150)
                else:
                    print(f" :| Build Dir Not found")
            else:
                print(f":| .O Files Dir Not Found")
        else:
            print(f":| C Module Dir Not Found")

if __name__ == "__main__":
    gc = Compiler()


