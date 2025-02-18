/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Gets cpus values within a struct.
*/

#include "include.h"

void cpu_sum(cpus_t *cpu)
{
    cpu->tot += cpu->user;
    cpu->tot += cpu->nice;
    cpu->tot += cpu->sys;
    cpu->tot += cpu->idle;
    cpu->tot += cpu->iowait;
    cpu->tot += cpu->irq;
    cpu->tot += cpu->softirq;
    cpu->tot += cpu->stolen;
}

cpus_t *getcpus(void)
{
    cpus_t *cpu = calloc(1, sizeof(cpus_t));
    FILE *file = fopen("/proc/stat", "r");
    char *buffer = calloc(100, 1);

    if (file != NULL) {
        fgets(buffer, 99, file);
        cpu->user = atoi(jump_to(buffer, ' ', 1));
        cpu->nice = atoi(jump_to(buffer, ' ', 2));
        cpu->sys = atoi(jump_to(buffer, ' ', 3));
        cpu->idle = atoi(jump_to(buffer, ' ', 4));
        cpu->iowait = atoi(jump_to(buffer, ' ', 5));
        cpu->irq = atoi(jump_to(buffer, ' ', 6));
        cpu->softirq = atoi(jump_to(buffer, ' ', 7));
        cpu->stolen = atoi(jump_to(buffer, ' ', 8));
        cpu_sum(cpu);
        fclose(file);
    }
    free(buffer);
    return cpu;
}

char *my_getcpus(void)
{
    cpus_t *cpu = getcpus();
    char *str = cpu != NULL ? calloc(200, 1) : NULL;
    double user = (double)cpu->user / cpu->tot * 100;
    double sys = (double)cpu->sys / cpu->tot * 100;
    double nice = (double)cpu->nice / cpu->tot * 100;
    double idle = (double)cpu->idle / cpu->tot * 100;
    double iowait = (double)cpu->iowait / cpu->tot * 100;
    double irq = (double)cpu->irq / cpu->tot * 100;
    double softirq = (double)cpu->irq / cpu->tot * 100;
    double stolen = (double)cpu->stolen / cpu->tot * 100;

    free(cpu);
    if (str != NULL) {
        sprintf(str, "\n%%Cpu(s):%5.1f us,%5.1f sy,", user, sys);
        sprintf(str + strlen(str), "%5.1f ni,%5.1f id,", nice, idle);
        sprintf(str + strlen(str), "%5.1f wa,%5.1f hi,", iowait, irq);
        sprintf(str + strlen(str), "%5.1f si,%5.1f st", softirq, stolen);
    }
    return str;
}
//        sprintf(str + strlen(str), "%5.1f si,%5.1f st,")
