import sys
import os
import json
import subprocess
import time
import win32com.client

MATLAB_EXE = r"D:\MATLAB\R2022b\bin\win64\MATLAB.exe"

class MatlabBridge:
    """Persistent MATLAB COM bridge."""
    
    def __init__(self):
        self._ml = None
        self._pid = None
    
    def connect(self):
        """Connect to MATLAB via COM. Starts MATLAB if needed."""
        try:
            self._ml = win32com.client.Dispatch("Matlab.Application")
            self._ml.Visible = 0
            return True, "connected"
        except Exception as e:
            # Try starting MATLAB first
            try:
                subprocess.Popen(
                    [MATLAB_EXE, "/MLAutomation", "/nosplash", "/minimize"],
                    stdout=subprocess.DEVNULL,
                    stderr=subprocess.DEVNULL
                )
                time.sleep(5)
                for attempt in range(10):
                    try:
                        self._ml = win32com.client.Dispatch("Matlab.Application")
                        self._ml.Visible = 0
                        return True, "started+connected"
                    except:
                        time.sleep(2)
                return False, "timeout waiting for MATLAB"
            except Exception as e2:
                return False, f"failed: {e2}"
    
    def execute(self, command):
        """Execute a MATLAB command and return the output."""
        if not self._ml:
            ok, msg = self.connect()
            if not ok:
                return {"success": False, "output": msg}
        try:
            result = self._ml.Execute(command)
            return {"success": True, "output": result}
        except Exception as e:
            # Try reconnect
            self._ml = None
            ok, msg = self.connect()
            if not ok:
                return {"success": False, "output": str(e) + "; reconnect: " + msg}
            try:
                result = self._ml.Execute(command)
                return {"success": True, "output": result}
            except Exception as e2:
                return {"success": False, "output": str(e2)}
    
    def close(self):
        """Close MATLAB."""
        if self._ml:
            try:
                self._ml.Quit()
            except:
                pass
            self._ml = None

def main():
    if len(sys.argv) < 2:
        print(json.dumps({"success": False, "output": "Usage: python matlab_com.py <command>"}))
        return
    
    command = sys.argv[1]
    bridge = MatlabBridge()
    
    if command == "--close":
        bridge.connect()
        bridge.close()
        print(json.dumps({"success": True, "output": "MATLAB closed"}))
        return
    
    result = bridge.execute(command)
    print(json.dumps(result, ensure_ascii=False))

if __name__ == "__main__":
    main()
