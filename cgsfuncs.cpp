#include <QDebug>
#include "cgsfuncs.h"

QStringList getSpaces()
{
    QStringList sL;
    CFArrayRef spaces = CGSCopySpaces(CGSDefaultConnection, kCGSSpaceAll);

    qDebug() << "spaces: " << spaces;

    int i;

    for(i = 0; i < CFArrayGetCount(spaces); i++) {
        CGSSpace space = (CGSSpace)CFArrayGetValueAtIndex(spaces, i);

        CFShow(CGSSpaceCopyName(CGSDefaultConnection, space));
        printf("i: %i", i);
        printf("Space ID: %lld\n", space);
        printf("Absolute level: %d\n", CGSSpaceGetAbsoluteLevel(CGSDefaultConnection, space));
        printf("Compat ID: %d\n", CGSSpaceGetCompatID(CGSDefaultConnection, space));
        printf("Type: %d\n", CGSSpaceGetType(CGSDefaultConnection, space));
        printf("\n");

        sL.push_back(QString::number(space));
    }
    printf("-----------------\n");
    return sL;
}
