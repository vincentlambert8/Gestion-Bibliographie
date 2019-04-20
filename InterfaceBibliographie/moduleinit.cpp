/**
 * \file moduleinit.cpp
 * \brief Implantation de la classe ModuleInit permettant de passer du codec ASCII à UTF-8
 * \author Vincent Lambert
 * \version 1.0
 * \date 20/04/2019
 */

#include <qtextcodec.h>

class ModuleInit {
    static ModuleInit *instance;
public:
    ModuleInit() {
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
    }
};
ModuleInit * ModuleInit::instance = new ModuleInit();


