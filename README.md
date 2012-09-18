Android_USpace_FTraceManager
============================

A user space library for managing FTrace when running on an Android device. Convenience methods really...

Native
======
* This reads from the FTrace trace output pipe and records it into a file. This allows for longer traces to be recorded. This does go through userspace and back down so it may have an affect on experimental results.
* I have a problem at the moment with printing out from native programs to logcat or the shell. This is because by default adb redirects stdout to /dev/null. The fixes others are suggesting aren't working.
  * I intend to fix this in the future by linking this program against the Android Logging headers, which means I can use the Android logging framework to print stuff out. 