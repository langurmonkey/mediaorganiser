## Media organiser

This program organises a bunch of media files in folders by date with the format `./YYYYMM`.
It recognises the following prefixes:
*  `IMG-` + date
*  `IMG_` + date
*  `VID-` + date
*  `VID_` + date
*  `PANO_` + date
*  `PHOTO_` + date

It also recognises dates in the filename as `YYYY-MM-DD`. If the script can't work out the date, then it copies the file to an `./undated` folder.

### Usage
```
mediaorganiser -i INPUT_FOLDER -o OUTPUT_FOLDER
```

Here are all the arguments:
```
General options:
-h [ --help ]         print help
-i [ --input ] arg    input folder
-o [ --output ] arg   output folder
-c [ --copy ]         if specified, files are copied instead of moved
```

If the output folder is not given, the output is set to the input folder.
