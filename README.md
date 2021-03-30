<h1 align="center">
  <br>
  <a href="https://github.com/burmaraider/INIReader/archive/refs/heads/master.zip">
  INIReader
</h1>

<h4 align="center">A lightweight, easy to use INI file reader</h4>

<p align="center">
    <img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/burmaraider/INIReader">
    <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/burmaraider/INIReader">
    <img alt="GitHub pull requests" src="https://img.shields.io/github/issues-pr/burmaraider/INIReader">
</p>
      
<p align="center">
  <a href="#about">About</a> •
  <a href="#installation">Installation</a> •
  <a href="#functions">Functions</a> •
  <a href="#features">Features</a> •
  <a href="#support">Support</a> •
  <a href="#license">License</a>
</p>

---

## About

<table>
<tr>
<td>
  
**INIReader** is a **lightweight** and easy to use INI file parser written in C++. It was designed because I simply didn't like the other offerings, but also to learn some C++.

It is a **single** header and cpp file. Easy to include in any project and will compile on any compiler.

![INIReader Sample](https://raw.githubusercontent.com/burmaraider/INIReader/master/.github/inireaderimage.png)
<p align="right">
<sub>(Preview)</sub>
</p>

</td>
</tr>
</table>

## Installation

##### Downloading and installing steps:
* **[Download](https://github.com/burmaraider/INIReader/archive/refs/heads/master.zip)** the latest version of the INIReader.
* **Include** `INIReader.h` to your project
  * Setup a new INIReader object ``INIReader inifile``.
  * That's it!

## Functions:

* `ReadFile` - Reads file based on the ***filename*** you supply
* `SaveFile` - Saves file based on the ***filename*** you supply
* `AddSection` - Adds a new **[Section]** to the interal list
* `AddKeyValue` - Adds a new <span style="color:#21599e">**Key = Value**</span>  pair to the **[Section]** specified
* `RemoveKeyValueFromSection` - Removes <span style="color:#21599e">**Key = Value**</span>  pair to the **[Section]** specified
* `RemoveSection` - Removes **[Section]** and any <span style="color:#21599e">**Key = Value**</span>  pair associated
* `GetValueFromKey` - Retrieves a string  from <span style="color:#21599e">**Key = Value**</span> pair from **[Section]** specified
* `PrintFileDebug` - Spits out the file using `printf`

## Features

|                            | 🔩 INIReader       | ◾ Other INI Readers |
| -------------------------- | :----------------: | :-----------------: |
| Small                      |         ✔️         |         ✔️         |
| Lightweight                |         ✔️         |         ✔️         |
| Easy to use                |         ✔️         |         ❌         |

Not exactly the best in the world, but it gets the job done.

## Support

Reach out to me at one of the following places if you so wish:

- E-Mail: **burmaraider@gmail.com**

## License

[![License: LGPL v3](https://img.shields.io/badge/License-LGPL%20v3-blue.svg?style=flat-square)](https://tldrlegal.com/license/gnu-lesser-general-public-license-v3-(lgpl-3))