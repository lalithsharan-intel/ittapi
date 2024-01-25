import platform

def isLinux():
    return platform.system() == "Linux"

def isWindows():
    return platform.system() == "Windows"

