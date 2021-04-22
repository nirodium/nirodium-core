// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2017-2018 The NRDI developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "uritests.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("nirodium:nU7Xy8o43rzHTV5SCzqnUbNfxRp9TJfmxj?req-dontexist="));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("nirodium:nU7Xy8o43rzHTV5SCzqnUbNfxRp9TJfmxj?dontexist="));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("nU7Xy8o43rzHTV5SCzqnUbNfxRp9TJfmxj"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("nirodium:nU7Xy8o43rzHTV5SCzqnUbNfxRp9TJfmxj?label=Some Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("nU7Xy8o43rzHTV5SCzqnUbNfxRp9TJfmxj"));
    QVERIFY(rv.label == QString("Some Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("nirodium:nU7Xy8o43rzHTV5SCzqnUbNfxRp9TJfmxj?amount=0.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("nU7Xy8o43rzHTV5SCzqnUbNfxRp9TJfmxj"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("nirodium:nU7Xy8o43rzHTV5SCzqnUbNfxRp9TJfmxj?amount=1.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("nU7Xy8o43rzHTV5SCzqnUbNfxRp9TJfmxj"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("nirodium:nU7Xy8o43rzHTV5SCzqnUbNfxRp9TJfmxj?amount=100&label=Some Example"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("nU7Xy8o43rzHTV5SCzqnUbNfxRp9TJfmxj"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Some Example"));

    uri.setUrl(QString("nirodium:nU7Xy8o43rzHTV5SCzqnUbNfxRp9TJfmxj?message=Some Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("nU7Xy8o43rzHTV5SCzqnUbNfxRp9TJfmxj"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseBitcoinURI("nirodium://nU7Xy8o43rzHTV5SCzqnUbNfxRp9TJfmxj?message=Some Example Address", &rv));
    QVERIFY(rv.address == QString("nU7Xy8o43rzHTV5SCzqnUbNfxRp9TJfmxj"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("nirodium:nU7Xy8o43rzHTV5SCzqnUbNfxRp9TJfmxj?req-message=Some Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("nirodium:nU7Xy8o43rzHTV5SCzqnUbNfxRp9TJfmxj?amount=1,000&label=Some Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("nirodium:nU7Xy8o43rzHTV5SCzqnUbNfxRp9TJfmxj?amount=1,000.0&label=Some Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));
}
