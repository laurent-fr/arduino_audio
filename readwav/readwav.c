// readwav, produce a C header file from a 16 bits signed WAV file
// the base code was found here : http://ubuntuforums.org/showthread.php?t=968690

#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

int main(int argc,char *argv[])
    {
    SNDFILE *sf;
    SF_INFO info;
    int  num_items;
    int num;
    short *buf;
    int f,sr,c;
    int i,j;
    FILE *out;
    
    /* Open the WAV file. */
    if (argc!=2) {
	printf("Usage: readwav <file.wav>\n");
	printf("The wav file must be 16bits signed.\n");
	printf("It will produce a file called 'sound_data.h'\n");
	exit(0);
    }

    info.format = 0;
    sf = sf_open(argv[1],SFM_READ,&info);
    if (sf == NULL)
        {
        printf("Failed to open the file.\n");
        exit(-1);
        }

    /* Print some of the info, and figure out how much data to read. */
    f = info.frames;
    sr = info.samplerate;
    c = info.channels;
    printf("frames=%d\n",f);
    printf("samplerate=%d\n",sr);
    printf("channels=%d\n",c);
    num_items = f*c;
    printf("num_items=%d\n",num_items);

    /* Allocate space for the data to be read, then read it. */
    buf = (short *) malloc(num_items*sizeof(short));
    num = sf_read_short(sf,buf,num_items);
    sf_close(sf);
    printf("Read %d items\n",num);
    /* Write the data to filedata.out. */
    out = fopen("sound_data.h","w");

    fprintf(out,"int16_t sound_data[]= {");

    for (i = 0; i < num; i += c)
        {
        for (j = 0; j < c; ++j)
            fprintf(out,"%d, ",buf[i+j]);
        }


    fprintf(out,"0};\n");
    fclose(out);

    return 0;
}


