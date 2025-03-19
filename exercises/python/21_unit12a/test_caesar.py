# @copyright 2011 Günter Kolousek

from caesar import *


def test_encrypt1():
    assert encrypt1("xyz abc") == "ABC DEF", "Fehler bei encrypt1"
    assert encrypt1("Maxi ist gerne Eis") == "PDAL LVW JHUQH HLV", \
        "Fehler bei encrypt1"


def test_decrypt1():
    assert decrypt1("ABC DEF") == "XYZ ABC", "Fehler bei decrypt1"
    assert decrypt1("PDAL LVW JHUQH HLV") == "MAXI IST GERNE EIS", \
        "Fehler bei decrypt1"


def test_invert_dict():
    assert invert_dict({}) == {}, "Fehler beim Invertieren eines leeren dict"
    assert invert_dict({1: 2, 2: 3}), "Fehler beim Invertien eines dict"


def test_encrypt2():
    assert encrypt2("truppen", 0) == "TRUPPEN",\
        "Fehler bei encrypt2: Passwort 0"
    assert encrypt2("truppen", 1) == "USVQQFO",\
        "Fehler bei encrypt2: Passwort 1"
    assert encrypt2("truppen", 2) == "VTWRRGP",\
        "Fehler bei encrypt2: Passwort 2"
    assert encrypt2("truppen", 3) == "WUXSSHQ",\
        "Fehler bei encrypt2: Passwort 3"
    assert encrypt2("truppen", 4) == "XVYTTIR",\
        "Fehler bei encrypt2: Passwort 4"
    assert encrypt2("truppen", 5) == "YWZUUJS",\
        "Fehler bei encrypt2: Passwort 5"
    assert encrypt2("truppen", 6) == "ZXAVVKT",\
        "Fehler bei encrypt2: Passwort 6"
    assert encrypt2("truppen", 7) == "AYBWWLU",\
        "Fehler bei encrypt2: Passwort 7"


def test_decrypt2():
    assert decrypt2("TRUPPEN", 0) == "TRUPPEN",\
        "Fehler bei decrypt2 bei Passwort 0"
    assert decrypt2("USVQQFO", 1) == "TRUPPEN",\
        "Fehler bei decrypt2 bei Passwort 1"
    assert decrypt2("VTWRRGP", 2) == "TRUPPEN",\
        "Fehler bei decrypt2 bei Passwort 2"
    assert decrypt2("WUXSSHQ", 3) == "TRUPPEN",\
        "Fehler bei decrypt2 bei Passwort 3"
    assert decrypt2("XVYTTIR", 4) == "TRUPPEN",\
        "Fehler bei decrypt2 bei Passwort 4"
    assert decrypt2("YWZUUJS", 5) == "TRUPPEN",\
        "Fehler bei decrypt2 bei Passwort 5"
    assert decrypt2("ZXAVVKT", 6) == "TRUPPEN",\
        "Fehler bei decrypt2 bei Passwort 6"
    assert decrypt2("AYBWWLU", 7) == "TRUPPEN",\
        "Fehler bei decrypt2 bei Passwort 7"


def test_encrypt3():
    assert encrypt3("truppen", 0) == "truppen", "Fehler bei Passwort 0"
    assert encrypt3("truppen", 1) == "usvqqfo", "Fehler bei Passwort 1"
    assert encrypt3("truppen", 2) == "vtwrrgp", "Fehler bei Passwort 2"
    assert encrypt3("truppen", 3) == "wuxsshq", "Fehler bei Passwort 3"
    assert encrypt3("truppen", 4) == "xvyttir", "Fehler bei Passwort 4"
    assert encrypt3("truppen", 5) == "ywzuujs", "Fehler bei Passwort 5"
    assert encrypt3("truppen", 6) == "zxavvkt", "Fehler bei Passwort 6"
    assert encrypt3("truppen", 7) == "aybwwlu", "Fehler bei Passwort 7"


def test_decrypt3():
    assert decrypt3("truppen", 0) == "truppen", "Fehler bei Passwort 0"
    assert decrypt3("Usvqqfo", 1) == "Truppen", "Fehler bei Passwort 1"
    assert decrypt3("VTwrrgp", 2) == "TRuppen", "Fehler bei Passwort 2"
    assert decrypt3("WUXsshq", 3) == "TRUppen", "Fehler bei Passwort 3"
    assert decrypt3("XVYTtir", 4) == "TRUPpen", "Fehler bei Passwort 4"
    assert decrypt3("YWZUUjs", 5) == "TRUPPen", "Fehler bei Passwort 5"
    assert decrypt3("ZXAVVKt", 6) == "TRUPPEn", "Fehler bei Passwort 6"
    assert decrypt3("AYBWWLU", 7) == "TRUPPEN", "Fehler bei Passwort 7"


def test_encrypt_translate_msg():
    assert translate_msg(1, "truppen", 0) == "truppen",\
        "Fehler bei Passwort 0"
    assert translate_msg(1, "truppen", 1) == "usvqqfo",\
        "Fehler bei Passwort 1"
    assert translate_msg(1, "truppen", 2) == "vtwrrgp",\
        "Fehler bei Passwort 2"
    assert translate_msg(1, "truppen", 3) == "wuxsshq",\
        "Fehler bei Passwort 3"
    assert translate_msg(1, "truppen", 4) == "xvyttir",\
        "Fehler bei Passwort 4"
    assert translate_msg(1, "truppen", 5) == "ywzuujs",\
        "Fehler bei Passwort 5"
    assert translate_msg(1, "truppen", 6) == "zxavvkt",\
        "Fehler bei Passwort 6"
    assert translate_msg(1, "truppen", 7) == "aybwwlu",\
        "Fehler bei Passwort 7"


def test_decrypt_translate_msg():
    assert translate_msg(-1, "truppen", 0) == "truppen", "Fehler bei Passwort 0"
    assert translate_msg(-1, "uSVQQFO", 1) == "tRUPPEN", "Fehler bei Passwort 1"
    assert translate_msg(-1, "vtWRRGP", 2) == "trUPPEN", "Fehler bei Passwort 2"
    assert translate_msg(-1, "wuxSSHQ", 3) == "truPPEN", "Fehler bei Passwort 3"
    assert translate_msg(-1, "xvytTIR", 4) == "trupPEN", "Fehler bei Passwort 4"
    assert translate_msg(-1, "ywzuuJS", 5) == "truppEN", "Fehler bei Passwort 5"
    assert translate_msg(-1, "zxavvkT", 6) == "truppeN", "Fehler bei Passwort 6"
    assert translate_msg(-1, "aybwwlu", 7) == "truppen", "Fehler bei Passwort 7"
