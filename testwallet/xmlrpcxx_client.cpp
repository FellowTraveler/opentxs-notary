/************************************************************************************
 *    
 *  xmlrpcxx_client.cpp  (the XmlRpc++ version of the client -- Web Services version.)
 *  
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA256
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, and GUI 
 *    
 *    	 -- Anonymous Numbered Accounts.
 *    	 -- Untraceable Digital Cash.
 *    	 -- Triple-Signed Receipts.
 *    	 -- Cheques, Vouchers, Transfers, Inboxes.
 *    	 -- Basket Currencies, Markets, Payment Plans.
 *    	 -- Signed, XML, Ricardian-style Contracts.
 *    
 *  Copyright (C) 2010-2012 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *  
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki 
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *    
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- OTLib.........A class library.......LICENSE:...LAGPLv3 
 *   -- OT-API........A client API..........LICENSE:...LAGPLv3
 *   -- testwallet....Command-line client...LICENSE:...LAGPLv3
 *   -- OT-Server.....Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (livewire_3001@yahoo.com).
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *    
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT-API, then you
 *   don't have to open-source your code--only your changes to
 *   Open Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open Transactions terms remain respected, with regard to
 *   the Open Transactions code itself.
 *    
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/OTLib/Lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *   
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.
 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.11 (Darwin)
 
 iQIcBAEBCAAGBQJOjvvUAAoJEAMIAO35UbuOBlMP/1LX0xJ9CrTOe1G/mgc+VygT
 JPVZDAbQDL/lJXOZMbaPJ/GaLXyEnTViHp97ERrlVuBQz+9uonIKCmPqAGYGVBG1
 MGV2QcscXU2aOUT1VPf2OYEOIul0h8FX2lixfqouH9/OkVsGRLr79Zu8z3zdsO4R
 ktQtjZEU6lnL2t6cmp/cuXlQnbz1xvxd56xNDR11YP07Z4x+CuDB4EAK+P9TfCwn
 tqq5yJmxJM9HtMoi3cUU7kXodKm1n1YZt7O46DOxHqbXqErHChN1ekSK0fXad614
 Gmh+5JfvHjx5XoFWMxb46aAAcUiG8+QpFBcKtSYP2X96k1ylgxMCzrK60ec/MxKV
 BzvP00OJ6PzzrTlcUaCgJ8ZX+0scOMvW0XKioEorozKSWNFvT4Drc4Thhy8u9ET3
 ru1enNFrjdxKjw2+ZTQcKSZjSRx2kMQ2od/dkqUlhe/M1cHGhseH6ls7pItrkykE
 ufZ9GlZoxYE+FRatIBPneT9WwsvFFvH+i6cQ/MM9pbTr19g6VPzVZ4U9E65BbTDB
 czITynH+uMtJLbprtCdQlsI+vqTgYNoY8AUsmnr1qUkp020qGlvwfCJVrooisTmm
 yIh+Yp/KBzySU3inzclaAfv102/t5xi1l+GTyWHiwZxlyt5PBVglKWx/Ust9CIvN
 6h9BYZFTZrh/OwBXCdAv
 =MUfS
 -----END PGP SIGNATURE-----
 **************************************************************/



#define KEY_PASSWORD        "test"


#define OT_OPTIONS_FILE_DEFAULT	"command-line-ot.opt"
#define OT_INI_FILE_DEFAULT	"ot_init.cfg"
#define OT_PROMPT_HELPFILE "CLIENT-COMMANDS.txt"

// ---------------------------------------------------------------------------

#ifdef _WIN32
#define OT_FOLDER_DEFAULT   "C:\\~\\Open-Transactions"
#define MAIN_PATH_DEFAULT	"C:\\~\\Open-Transactions\\client_data"

#define CA_FILE             "certs\\special\\ca.crt"
#define KEY_FILE            "certs\\special\\client.pem"

// ---------------------------------------------------------------------------

#else

#define OT_FOLDER_DEFAULT   "~/.ot"
#define MAIN_PATH_DEFAULT	"~/.ot/client_data"

#define CA_FILE             "certs/special/ca.crt"
#define KEY_FILE            "certs/special/client.pem"

#endif

// ---------------------------------------------------------------------------

#include <cstring>
#include <cstdio>
#include <cstdlib>


#include <string>

#include <iostream>


extern "C" 
{
#ifdef _WIN32
#include <WinSock.h>
#else
#include <netinet/in.h>
#endif
}



#include "SimpleIni.h"



// ---------------------------------------------------------------------------

#if defined(OT_ZMQ_MODE)

#include <zmq.hpp>


// If you build in tcp/ssl mode, this file will build even if you don't have this library.
// But if you build in xml/rpc/http mode, 
//#ifdef _WIN32
//#include "timxmlrpc.h" // XmlRpcC4Win
//#else
//#include "XmlRpc.h"  // xmlrpcpp
//using namespace XmlRpc;
//#endif

#endif
// ---------------------------------------------------------------------------

#ifdef _WIN32
void OT_Sleep(int nMS);
#endif

// ---------------------------------------------------------------------------


#include "OTStorage.h"

#include "OTString.h"
#include "OTASCIIArmor.h"
#include "OTClient.h"
#include "OTServerConnection.h"
#include "OTMessage.h"
#include "OTString.h"
#include "OTWallet.h"
#include "OTPseudonym.h"
#include "OTEnvelope.h"
#include "OTPurse.h"
#include "OTCheque.h"
#include "OpenTransactions.h"
#include "OTPaymentPlan.h"
#include "OTLog.h"

// ---------------------------------------------------------------------------



// This global variable contains an OTWallet, an OTClient, etc. 
// It's the C++ high-level interace to OT. 
// Any client software will have an instance of this.
OT_API g_OT_API; 
// Note: Must call OT_API::Init() followed by g_OT_API.Init() in the main function, before using OT.


// ---------------------------------------------------------------------------

/*
 OT by default will look here: "~/.ot/ot_init.cfg"
 
 Inside that file are these contents:
 [paths]
 client_path=~/.ot/client_data
 server_path=~/.ot/server_data

 If none of the snazzy ini files or config files, or client_data/server_data folders
 are found, then the default locations are ./client_data and ./server_data
 MEANING: If it can't find it in your $HOME/.ot/ot_init.cfg file, then it looks
 in the current directory instead.
 
 (I'm REMOVING the option to pass the location in on the command line, at least without a switch.)
 */



#include "anyoption.h"


void HandleCommandLineArguments( int argc, char* argv[], AnyOption * opt );


/*

 --server     (SERVER_ID)
 
 USAGE:  ot -COMMAND [AMOUNT] [--from ACCT/NYM/ASSET] [--to ACCT or NYM]
 
  ot -w 100    (WITHDRAW 100 FROM DEFAULT ACCOUNT.)
  ot -d 100    (DEPOSIT FROM DEFAULT PURSE TO DEFAULT ACCOUNT.)
  ot -t 100 --to j43k  (TRANSFER 100 FROM DEFAULT ACCT TO ACCT STARTING WITH j43k)
  ot -t 100 --from qwer --to j43k  (TRANSFER 100 from ACCT STARTING WITH qwer TO ACCT starting j43k)

 */


void OT_Main_Cleanup()
{
#ifdef _WIN32
	WSACleanup();
#endif
}



// If false, error happened, usually based on what user just attemped.
//
bool SetupPointersForWalletMyNymAndServerContract(std::string & str_ServerID,
                                                  std::string & str_MyNym,
                                                  OTPseudonym *& pMyNym, 
                                                  OTWallet *& pWallet, 
                                                  OTServerContract *& pServerContract)
{
    // If we got down here, that means there were no commands on the command line 
    // (That's why we dropped into the OT prompt.)
    // However, there still may have been OPTIONS -- and if so, we'll go ahead and
    // load the wallet. (If there were NOT ANY OPTIONS, then we do NOT load the wallet,
    // although there is a COMMAND for doing that.)
    //
    const OTString strTheWalletFilename("wallet.xml"); // todo stop hardcoding.
    
    g_OT_API.LoadWallet(strTheWalletFilename);
//	g_OT_API.GetWallet()->SaveWallet("NEWwallet.xml"); // todo remove this test code.

    // -----------------------------------------------------        
    //
    pWallet = g_OT_API.GetWallet();
    
    if (NULL == pWallet)
    {
        OTLog::Output(0, "The wallet object is still NULL, somehow. Please load it.\n");
        return false;
    }
    
    // Below this point, pWallet is available :-)
    // -----------------------------------------------------
    
    if (str_ServerID.size() > 0 )
    {        
        const OTIdentifier SERVER_ID(str_ServerID.c_str());
        
        pServerContract = pWallet->GetServerContract(SERVER_ID);
        // If failure, then we try PARTIAL match.
        if (NULL == pServerContract)
            pServerContract = pWallet->GetServerContractPartialMatch(str_ServerID);
        
        if (NULL == pServerContract)
        {
            OTLog::Output(0, "Unable to find a server contract. Please use the option:  --server SERVER_ID\n"
                          "(Where SERVER_ID is the server ID. Partial matches ARE accepted.)\n"
                          "Also, see default values located in ~/.ot/comand-line-ot.opt \n");
            return false;
        }
        
    }
    // Below this point, pServerContract MAY be available, but also may be NULL.
    //
    // ------------------------------------------------------------------------------			
    
    if ( str_MyNym.size() > 0 )
    {
        const OTIdentifier MY_NYM_ID(str_MyNym.c_str());
        
        pMyNym = pWallet->GetNymByID(MY_NYM_ID);
        // If failure, then we try PARTIAL match.
        if (NULL == pMyNym)
            pMyNym = pWallet->GetNymByIDPartialMatch( str_MyNym );
        
        if (NULL == pMyNym)
        {
            OTLog::Output(0, "Unable to find My Nym. Please use the option:   --mynym USER_ID\n"
                          "(Where USER_ID is the Nym's ID. Partial matches ARE accepted.)\n"
                          "Also, see default values located in ~/.ot/comand-line-ot.opt \n");
            return false;
        }
    } // Below this point, pMyNym MIGHT be a valid pointer, or MIGHT be NULL.
        
    // Below THIS point, there's no guarantee of pWallet, though it MIGHT be there.
    // Same with pServerContract. (MIGHT be there.)
    
    return true;
}








void HandleCommandLineArguments( int argc, char* argv[], AnyOption * opt)
{
    if (NULL == opt)
        return;
    
    
    /* 1. CREATE AN OBJECT */
//    AnyOption *opt = new AnyOption();
//    OT_ASSERT(NULL != opt);
//    OTCleanup<AnyOption> theOptionAngel(opt);
    
	// -----------------------------------------------------
    /* 2. SET PREFERENCES  */
    //opt->noPOSIX(); /* do not check for POSIX style character options */
    //opt->setVerbose(); /* print warnings about unknown options */
    //opt->autoUsagePrint(true); /* print usage for bad options */
    
	// -----------------------------------------------------
    /* 3. SET THE USAGE/HELP   */
    opt->addUsage( "" );
    opt->addUsage( "OT CLI Usage:  " );
    opt->addUsage( "" );
    opt->addUsage( "ot  --stat            (Prints the wallet contents)" );
    opt->addUsage( "ot  [-h|-?|--help]    (Prints this help) " );
    opt->addUsage( "The '|' symbol means use --balance or -b, use --withdraw or -w, etc." );
    opt->addUsage( "The brackets '[]' show required arguments, where default values are" );
    opt->addUsage( "normally expected to be found in:   ~/.ot/command-line-ot.opt" );
    opt->addUsage( "ot  --balance  | -b          [--myacct <acct_id>]   (Display account balance)" );
    opt->addUsage( "ot  --withdraw | -w <amount> [--myacct <acct_id>]   (Withdraw as CASH)" );
    opt->addUsage( "ot  --transfer | -t <amount> [--myacct <acct_id>] [--hisacct <acct_id>]" );
    opt->addUsage( "ot  --cheque   | -c <amount> [--myacct <acct_id>] [--hisnym  <nym_id> ]" );
    opt->addUsage( "ot  --voucher  | -v <amount> [--myacct <acct_id>] [--hisnym  <nym_id> ]" );
    opt->addUsage( "ot  --depositcheque  [--myacct <acct_id>]   (Deposit a cheque.)" );
    opt->addUsage( "ot  --depositpurse   [--myacct <acct_id>]   (Deposit a cash purse.)" );
    opt->addUsage( "ot  --deposittokens  [--myacct <acct_id>]   (Deposit individual cash tokens.)" );
    opt->addUsage( "ot  --inbox    | -i  [--myacct <acct_id>]   (Display the inbox.)" );
    opt->addUsage( "ot  --sign     | -s  [--mynym  <nym_id> ]   (Sign a contract.)" );
    opt->addUsage( "ot  --verify         [--mynym  <nym_id> ]   (Verify a signature.)" );
    opt->addUsage( "ot  --purse    | -p   <arguments>           (Display a purse.)");
    opt->addUsage( "  Arguments:     [--mynym  <nym_id> ] [--mypurse <asset_type_id>]" );
    opt->addUsage( "ot  --refresh  | -r  [--myacct <acct_id>]    (Download account files from server.)");
    opt->addUsage( "ot  --refreshnym     [--mynym  <nym_id> ]    (Download nym files from server.)");
    opt->addUsage( "ot  --marketoffer    [--mynym  <nym_id> ]    (Place an offer on a market.)" );
    opt->addUsage( "Also, [--server <server_id>] will work with all of the above." );
    opt->addUsage( "" );
    opt->addUsage( "Recurring payments:" );
    opt->addUsage( "ot --proposeplan  <arguments>   (Merchant)" );
    opt->addUsage( "  Arguments: [--mynym  <nym_id> ] [--myacct  <acct_id>]  (continued.)" );
    opt->addUsage( "  Continued: [--hisnym <nym_id> ] [--hisacct <acct_id> ]");
    opt->addUsage( "ot --confirmplan  <arguments>   (Customer)" );
    opt->addUsage( "ot --activateplan <arguments>   (Customer again)" );
    opt->addUsage( "  Arguments: [--mynym  <nym_id> ] [--myacct  <acct_id>]" );
    opt->addUsage( "" );
    
    // -----------------------------------------------------
    /* 4. SET THE OPTION STRINGS/CHARACTERS */
    //
    // COMMAND LINE *AND* RESOURCE FILE
        
//  opt->setOption(  "server" );      /* an option (takes an argument), supporting only long form */
    
	// -----------------------------------------------------

    // COMMAND LINE ONLY
	/* for options that will be checked only on the command and line not in option/resource file */
//    opt->setCommandFlag(  "zip" , 'z'); /* a flag (takes no argument), supporting long and short form */
    opt->setCommandOption("withdraw" , 'w');   // withdraw from acct to purse, myacct, topurse
    opt->setCommandOption("transfer" , 't');   // transfer acct-to-acct, myacct, toacct
    opt->setCommandOption("cheque" ,   'c');   // write a cheque   myacct, tonym
    opt->setCommandOption("voucher" ,  'v');   // withdraw voucher myacct, tonym
    opt->setCommandFlag(  "marketoffer"   );   // add an offer to the market.
    opt->setCommandFlag(  "balance" ,  'b');   // Display account balance
    opt->setCommandFlag(  "depositcheque" );   // deposit a cheque to myacct
    opt->setCommandFlag(  "depositpurse"  );   // deposit cash purse to myacct
    opt->setCommandFlag(  "deposittokens" );   // deposit individual cash tokens to myacct
    opt->setCommandFlag(  "proposeplan"   );   // Merchant proposes a payment plan.
    opt->setCommandFlag(  "confirmplan"   );   // Customer confirms a payment plan.
    opt->setCommandFlag(  "activateplan"  );   // Customer activates a payment plan.
    opt->setCommandFlag(  "inbox" ,    'i');   // displays inbox (for ACCT_ID...)
    opt->setCommandFlag(  "sign" ,     's');   // sign a contract  mynym
    opt->setCommandFlag(  "verify"        );   // verify a signature
    opt->setCommandFlag(  "purse" ,    'p');   // display purse contents.
    opt->setCommandFlag(  "refresh" ,  'r');   // refresh intermediary files from server + verify against last receipt.
    opt->setCommandFlag(  "refreshnym"    );   // refresh intermediary files from server + verify against last receipt.
    opt->setCommandFlag(  "stat" );            // print out the wallet contents.
    
    opt->setCommandFlag("help", 'h');   // the Help screen.
    opt->setCommandFlag('?');           // the Help screen.
    
    /*
     --myacct   (ACCT ID)
     --mynym    (NYM ID)
     --mypurse  (ASSET TYPE ID)
     
     --toacct   (ACCT ID)
     --tonym    (NYM ID)
     --topurse  (ASSET TYPE ID)
     */  
    opt->setCommandOption("server");

    opt->setCommandOption("myacct");
    opt->setCommandOption("mynym");
    opt->setCommandOption("mypurse");
    opt->setCommandOption("hisacct");
    opt->setCommandOption("hisnym");
    opt->setCommandOption("hispurse");
    
    // NOTE: Above and Below me are IDs. This interface should allow PARTIAL IDs.
    // -----------------------------------------------------

    // RESOURCE FILE ONLY
	/* for options that will be checked only from the option/resource file */
    opt->setFileOption(  "defaultserver" ); /* an option (takes an argument), supporting only long form */

    opt->setFileOption(  "defaultmyacct" ); /* an option (takes an argument), supporting only long form */
    opt->setFileOption(  "defaultmynym" ); /* an option (takes an argument), supporting only long form */
    opt->setFileOption(  "defaultmypurse" ); /* an option (takes an argument), supporting only long form */
    opt->setFileOption(  "defaulthisacct" ); /* an option (takes an argument), supporting only long form */
    opt->setFileOption(  "defaulthisnym" ); /* an option (takes an argument), supporting only long form */
    opt->setFileOption(  "defaulthispurse" ); /* an option (takes an argument), supporting only long form */
/*    
    --defaultmyacct   (ACCT ID)
    --defaultmynym    (NYM ID)
    --defaultmypurse  (ASSET TYPE ID)
    
    --defaulttoacct   (ACCT ID)
    --defaulttonym    (NYM ID)
    --defaulttopurse  (ASSET TYPE ID)
*/
    
	// -----------------------------------------------------
    /* 5. PROCESS THE COMMANDLINE AND RESOURCE FILE */
    
	/* read options from a option/resource file with ':' separated options or flags, one per line */
    OTString strIniRAWFileDefault, strIniFileDefault;
    strIniRAWFileDefault.Format("%s%s%s", OT_FOLDER_DEFAULT, OTLog::PathSeparator(), OT_OPTIONS_FILE_DEFAULT);
    OTLog::TransformFilePath(strIniRAWFileDefault.Get(), strIniFileDefault);
    
	// -----------------------------------------------------
    opt->processFile( strIniFileDefault.Get() );  
	// -----------------------------------------------------    
    opt->processCommandArgs( argc, argv );
}



/*
 I'm starting to need this in possibly multiple places below, so I 
 made a function to avoid duplicating code. These are values such
 as "my account ID" and "his NymID" that are provided on the command
 line, and which also can be defaulted in a config file in ~/.ot
 */
void CollectDefaultedCLValues(AnyOption *opt,
                              std::string & str_ServerID,
                              std::string & str_MyAcct,
                              std::string & str_MyNym,
                              std::string & str_MyPurse,
                              std::string & str_HisAcct,
                              std::string & str_HisNym,
                              std::string & str_HisPurse)
{
    OT_ASSERT(NULL != opt);
    
    cerr << endl;
    
    // First we pre-set all the values based on the defaults from the options file.
    //
    if( opt->getValue( "defaultserver" ) != NULL )
        cerr << "Server default: " << (str_ServerID = opt->getValue( "defaultserver" )) << endl;

    if( opt->getValue( "defaultmyacct" ) != NULL )
        cerr << "MyAcct default: " << (str_MyAcct = opt->getValue( "defaultmyacct" )) << endl;
    if( opt->getValue( "defaultmynym" ) != NULL )
        cerr << "MyNym default: " << (str_MyNym = opt->getValue( "defaultmynym" )) << endl;
    if( opt->getValue( "defaultmypurse" ) != NULL )
        cerr << "MyPurse default: " << (str_MyPurse = opt->getValue( "defaultmypurse" )) << endl;

    if( opt->getValue( "defaulthisacct" ) != NULL )
        cerr << "HisAcct default: " << (str_HisAcct = opt->getValue( "defaulthisacct" )) << endl;
    if( opt->getValue( "defaulthisnym" ) != NULL )
        cerr << "HisNym default: " << (str_HisNym = opt->getValue( "defaulthisnym" )) << endl;
    if( opt->getValue( "defaulthispurse" ) != NULL )
        cerr << "HisPurse default: " << (str_HisPurse = opt->getValue( "defaulthispurse" )) << endl;

    // --------------
    // Next, we overwrite those with any that were passed in on the command line.

    if( opt->getValue( "server" ) != NULL )
        cerr << "Server from command-line: " << (str_ServerID = opt->getValue( "server" )) << endl;

    if( opt->getValue( "myacct" ) != NULL )
        cerr << "MyAcct from command-line: " << (str_MyAcct = opt->getValue( "myacct" )) << endl;
    if( opt->getValue( "mynym" ) != NULL )
        cerr << "MyNym from command-line: " << (str_MyNym = opt->getValue( "mynym" )) << endl;
    if( opt->getValue( "mypurse" ) != NULL )
        cerr << "MyPurse from command-line: " << (str_MyPurse = opt->getValue( "mypurse" )) << endl;

    if( opt->getValue( "hisacct" ) != NULL )
        cerr << "HisAcct from command-line: " << (str_HisAcct = opt->getValue( "hisacct" )) << endl;
    if( opt->getValue( "hisnym" ) != NULL )
        cerr << "HisNym from command-line: " << (str_HisNym = opt->getValue( "hisnym" )) << endl;
    if( opt->getValue( "hispurse" ) != NULL )
        cerr << "HisPurse from command-line: " << (str_HisPurse = opt->getValue( "hispurse" )) << endl;
}




// --------- MAIN FUNCTION -------------


int main(int argc, char* argv[])
{
	OTLog::vOutput(0, "\n\nWelcome to Open Transactions... Test Client -- version %s\n"
				   "(transport build: OTMessage -> OTEnvelope -> ZMQ )\n", 
				   OTLog::Version());
	
	OT_API::InitOTAPI();
	
	// **************************************************************************
	// The beginnings of an INI file!!

//#define OT_FOLDER_DEFAULT   "~/.ot"
//#define OT_INI_FILE_DEFAULT	"ot_init.cfg"
//
    OTString strIniRAWFileDefault, strIniFileDefault;
    strIniRAWFileDefault.Format("%s%s%s", OT_FOLDER_DEFAULT, OTLog::PathSeparator(), OT_INI_FILE_DEFAULT);
    OTLog::TransformFilePath(strIniRAWFileDefault.Get(), strIniFileDefault);
    // -------------------------------------------------------------------
	
    OTString strPath, strRawPath(MAIN_PATH_DEFAULT);
	
	{
		CSimpleIniA ini;
				
		SI_Error rc = ini.LoadFile(strIniFileDefault.Get());

		if (rc >=0)
		{
            {
                const char * pVal = ini.GetValue("paths", "client_path", MAIN_PATH_DEFAULT); // todo stop hardcoding.
                
                if (NULL != pVal)
                {
                    strRawPath.Set(pVal);
                    OTLog::vOutput(0, "Reading the ini file (%s): \n Found OT client_path: %s \n", 
                                   strIniFileDefault.Get(), strRawPath.Get());
                }
                else
                {
                    strRawPath.Set(MAIN_PATH_DEFAULT);
                    OTLog::vOutput(0, "There's no client_data path in the ini file (%s).\n Therefore, using: %s \n", 
                                   strIniFileDefault.Get(), strRawPath.Get());
                }
            }
		}
		else 
		{
			strRawPath.Set(MAIN_PATH_DEFAULT);
			OTLog::vOutput(0, "Unable to load ini file (%s) to find client_data path. \n Will assume that client data_folder is at path: %s \n", 
						   strIniFileDefault.Get(), strRawPath.Get());
		}
	}
	// **************************************************************************
	
    
	OTString strCAFile, strKeyFile; //, strSSLPassword;
	
    OTLog::TransformFilePath(strRawPath.Get(), strPath);
    // -------------------------------------------------------------------
    
    g_OT_API.Init(strPath);  // SSL gets initialized in here, before any keys are loaded.
	
	OTLog::vOutput(0, "Using client_data path:  %s\n", OTLog::Path());

	strCAFile. Format("%s%s%s", OTLog::Path(), OTLog::PathSeparator(), CA_FILE);
	strKeyFile.Format("%s%s%s", OTLog::Path(), OTLog::PathSeparator(), KEY_FILE);
	
	
    //  Prepare our context and socket
	zmq::context_t context(1);

	// -----------------------------------------------------------------------
    
    AnyOption *opt = new AnyOption();
    OT_ASSERT(NULL != opt);
    OTCleanup<AnyOption> theOptionAngel(opt);
    
    // Process the command line args
    //
    HandleCommandLineArguments( argc, argv, opt);

    
    // command line values such as account ID, Nym ID, etc. 
    // Also available as defaults in a config file in the ~/.ot folder
    //
    std::string str_ServerID;

    std::string str_MyAcct;
    std::string str_MyNym;
    std::string str_MyPurse;
    
    std::string str_HisAcct;
    std::string str_HisNym;
    std::string str_HisPurse;
    
    CollectDefaultedCLValues(opt,
                             str_ServerID,
                             str_MyAcct,
                             str_MyNym,
                             str_MyPurse,
                             str_HisAcct,
                             str_HisNym,
                             str_HisPurse);
    
    // -----------------------------------------------------
    /*  USAGE SCREEN (HELP) */
    //
    if( opt->getFlag( "help" ) || opt->getFlag( 'h' )  || opt->getFlag( '?' ) )
    {
        opt->printUsage();

        OT_Main_Cleanup();
        return 0;
    }
    // -----------------------------------------------------

    bool bIsCommandProvided = false;

    // See if there's a COMMAND chosen at command line.
    //
    if ( opt ->hasOptions())
    {
        // Below are COMMANDS (only one of them can be true...)
        //
        
        if( opt->getValue( 'w' ) != NULL  || opt->getValue( "withdraw" ) != NULL  )
        { bIsCommandProvided = true; cout << "withdraw amount = " << opt->getValue( 'w' ) << endl ; }
        else if( opt->getValue( 't' ) != NULL  || opt->getValue( "transfer" ) != NULL  )
        { bIsCommandProvided = true; cout << "transfer amount = " << opt->getValue( 't' ) << endl ; }
        else if( opt->getValue( 'c' ) != NULL  || opt->getValue( "cheque" ) != NULL  )
        { bIsCommandProvided = true; cout << "cheque amount = " << opt->getValue( 'c' ) << endl ; }
        else if(  opt->getFlag( "marketoffer" ) == true  )
        { bIsCommandProvided = true; cout << "marketoffer flag set " << endl ; }
        else if( opt->getValue( 'v' ) != NULL  || opt->getValue( "voucher" ) != NULL  )
        { bIsCommandProvided = true; cout << "voucher amount = " << opt->getValue( 'v' ) << endl ; }
        else if( opt->getFlag( "depositcheque" ) )
        { bIsCommandProvided = true; cout << "deposit cheque flag set " << endl ; }
        else if( opt->getFlag( "depositpurse" ) ) 
        { bIsCommandProvided = true; cout << "deposit purse flag set " << endl ; }
        else if( opt->getFlag( "deposittokens" ) ) 
        { bIsCommandProvided = true; cout << "deposit tokens flag set " << endl ; }
        else if( opt->getFlag( "proposepaymentplan" ) ) 
        { bIsCommandProvided = true; cout << "proposepaymentplan flag set " << endl ; }
        else if( opt->getFlag( "confirmpaymentplan" ) ) 
        { bIsCommandProvided = true; cout << "confirm payment plan flag set " << endl ; }
        else if( opt->getFlag( "activatepaymentplan" ) ) 
        { bIsCommandProvided = true; cout << "activate payment plan flag set " << endl ; }
        else if( opt->getFlag( 'b' )  || opt->getFlag( "balance" )  )
        { bIsCommandProvided = true; cout << "balance flag set " << endl ; }
        else if( opt->getFlag( 'i' )  || opt->getFlag( "inbox" )  )
        { bIsCommandProvided = true; cout << "inbox flag set " << endl ; }
        else if( opt->getFlag( 'p' ) || opt->getFlag( "purse" )  )
        { bIsCommandProvided = true; cout << "purse flag set " << endl ; }
        else if( opt->getFlag( 's' ) || opt->getFlag( "sign" ))
        { bIsCommandProvided = true; cout << "sign flag set " << endl ; }
        else if( opt->getFlag( "verify" )  )
        { bIsCommandProvided = true; cout << "verify flag set " << endl; }
        else if( opt->getFlag( "stat" )   )
        { bIsCommandProvided = true; cout << "stat flag set "  << endl ; }
        else if( opt->getFlag( 'r' ) || opt->getFlag( "refresh" )   )
        { bIsCommandProvided = true; cout << "refresh flag set "  << endl ; }
        else if( opt->getFlag( "refreshnym" )   )
        { bIsCommandProvided = true; cout << "refreshnym flag set "  << endl ; }
        
        cout << endl ;
    }
    else
        bIsCommandProvided = false;
    
    // -----------------------------------------------------
    //
	if( false == bIsCommandProvided)   // If no command was provided (though other command-line options may have been...) 
    {                           // then print some helpful information, and drop into the OT prompt. (Loop.)
//      opt->printUsage();
        
        OTLog::Output(0, "\nLOOKING FOR INSTRUCTIONS for the OT COMMAND LINE?\n"
                      "Try:   quit\n"
                      "Followed by:  ot -?\n"
                      "or:    ot -h\n"
                      "or:    ot --help\n"
                      "\n"
                      "(NOW ENTERING OT PROMPT) \n"
                      "Type \"Help\" at the OT> prompt to see contents of ~/.ot/CLIENT-COMMANDS.txt\n\n");
        
        // This causes us to drop into the OT prompt.
	}
    else // Else a command WAS provided at the command line, so we execute a single time, once just for that command.
    {         
        OTWallet * pWallet = NULL;
        OTServerContract * pServerContract = NULL;
        OTPseudonym * pMyNym = NULL;

        // This will load the wallet and, if Nym or Server IDs were provided, load those up as well.
        // (They may still be NULL after this call, however.)
        //
        if (false == SetupPointersForWalletMyNymAndServerContract(str_ServerID, str_MyNym, 
                                                                  pMyNym, pWallet, pServerContract))
        {
            OT_Main_Cleanup();
            return 0;
        }
        
        // Below this point, pWallet is available :-)
        // -----------------------------------------------------

        // Later I can split the below commands into "those that need a server contract"
        // and "those that don't need a server contract", and put this code between them.
        // That's what the OT Prompt loop does. For now I'm making things easy here by just
        // making it a blanket requirement.
        //
        if (NULL == pServerContract) 
        {
            OTLog::Output(0, "Unable to find a server contract to use. Please use the option: --server SERVER_ID\n"
                          "(Where SERVER_ID is the Server's ID. Partial matches ARE accepted.)\n");
            
            OT_Main_Cleanup();
            return 0;
        }

        const OTIdentifier theServerID(*pServerContract);
        const OTString strServerID(theServerID);

        // -----------------------------------------------------
    
        int			nServerPort = 0;
        OTString	strServerHostname;
        
        // ------------------------------------------------------------------------------			            
        // You can't just connect to any hostname and port.
        // Instead, you give me the Server Contract, and *I'll* look up all that stuff FOR you...
        // (We verify this up here, but use it at the bottom of the function once the message is set up.)
        //
        
        if (false == pServerContract->GetConnectInfo(strServerHostname, nServerPort))
        {
            OTLog::vError("Failed retrieving connection info from server contract: %s\n", 
                          strServerID.Get());
            OT_Main_Cleanup();
            return 0;
        }


        // Below this point, pWallet and pServerContract are both available.
        //
        // ***********************************************************
        
        OTAccount * pMyAccount  = NULL;
        OTAccount * pHisAccount = NULL;
        
        if( str_MyAcct.size() > 0 )
        {
         	const OTIdentifier MY_ACCOUNT_ID(str_MyAcct.c_str());
            
            pMyAccount = pWallet->GetAccount(MY_ACCOUNT_ID);
            // If failure, then we try PARTIAL match.
            if (NULL == pMyAccount)
                pMyAccount = pWallet->GetAccountPartialMatch( str_MyAcct );
            
            if (NULL == pMyAccount)
            {
                OTLog::vOutput(0, "Unable to find myacct: %s\n", str_MyAcct.c_str());
                OT_Main_Cleanup();
                return 0;
            }
        }
        // -------------------------------------------------------------------------
        // TODO: I wouldn't have HIS account in MY wallet -- I'd only have his account ID.
        // Therefore need to be able to retrieve this info from the ADDRESS BOOK (in order
        // to be able to do PARTIAL MATCHES...)
        //
        if ( str_HisAcct.size() > 0 )
        {
         	const OTIdentifier HIS_ACCOUNT_ID(str_HisAcct.c_str());
            
            pHisAccount = pWallet->GetAccount(HIS_ACCOUNT_ID);
            // If failure, then we try PARTIAL match.
            if (NULL == pHisAccount)
                pHisAccount = pWallet->GetAccountPartialMatch( str_HisAcct );
            
            if (NULL != pHisAccount)
            {
                OTString strTemp;
                pHisAccount->GetPurportedAccountID().GetString(strTemp);
                
                str_HisAcct = strTemp.Get();
                OTLog::vOutput(0, "Using as hisacct: %s\n", str_HisAcct.c_str());
            }
        }
        
        // ***********************************************************

        OTPseudonym * pHisNym = NULL;

        // I put this here too since I think it's required in all cases.
        //
        if (NULL == pMyNym) // Todo maybe move this check to the commands below (ONLY the ones that use a nym.)
        {
            OTLog::Output(0, "Unable to find My Nym. Please use the option:   --mynym USER_ID\n"
                          "(Where USER_ID is the Nym's ID. Partial matches ARE accepted.)\n");
            OT_Main_Cleanup();
            return 0;
        }

        const OTIdentifier MY_NYM_ID(*pMyNym);
        
        // -----------------------------------------------
        
        if ( str_HisNym.size() > 0 )
        {
         	const OTIdentifier HIS_NYM_ID(str_HisNym.c_str());
            
            pHisNym = pWallet->GetNymByID(HIS_NYM_ID);
            // If failure, then we try PARTIAL match.
            if (NULL == pHisNym)
                pHisNym = pWallet->GetNymByIDPartialMatch( str_HisNym );
            
            if (NULL != pHisNym)
            {
                OTString strTemp;
                pHisNym->GetIdentifier(strTemp);
                
                str_HisNym = strTemp.Get();
                OTLog::vOutput(0, "Using as 'HIS' nym: %s\n", str_HisNym.c_str());
            }
        }

        // Below this point, if Nyms or Accounts were specified, they are now available.
        // (Pointers might be null, though currently My Nym is required to be there.)
        //
        // ***********************************************************
        
        OTIdentifier thePurseAssetTypeID;
        OTAssetContract * pMyAssetContract = NULL;

        if ( str_MyPurse.size() > 0 )
        {
         	const OTIdentifier MY_ASSET_TYPE_ID(str_MyPurse.c_str());
            
            pMyAssetContract = pWallet->GetAssetContract(MY_ASSET_TYPE_ID);
            // If failure, then we try PARTIAL match.
            if (NULL == pMyAssetContract)
                pMyAssetContract = pWallet->GetAssetContractPartialMatch( str_MyPurse );
            
            if (NULL == pMyAssetContract)
            {
                OTLog::vOutput(0, "Unable to find My Asset Type: %s\n", str_MyPurse.c_str());
                OT_Main_Cleanup();
                return 0;
            }

            pMyAssetContract->GetIdentifier(thePurseAssetTypeID);
        }
        else
            thePurseAssetTypeID = pMyAccount->GetAssetTypeID();
        

        // TODO:  put "His Asset Contract" here, copied from above, if it turns out to be necessary.
        
        
        // BELOW THIS POINT, pMyAssetContract MIGHT be NULL, or MIGHT be an asset type specified by the user.
        // There's no guarantee that it's available, but if it IS, then it WILL be available below this point.
        // --------------------------------------------------------------------------
        
        
        // Also, pAccount and pMyAssetContract have not be validated AGAINST EACH OTHER (yet)...

    
         
        // -----------------------------------------------------
        /*  GET THE ACTUAL ARGUMENTS AFTER THE OPTIONS */
        //
//        for( int i = 0 ; i < opt->getArgc() ; i++ ){
//            cout << "arg = " <<  opt->getArgv( i ) << endl ;
//        }        
    
          
        bool bSendCommand	= false; // Determines whether to actually send a message to the server.
		
		OTMessage theMessage;
		
		// If we can match the user's request to a client command,
		// AND theClient object is able to process that request into
		// theMessage, then we send it down the pipe.
		

        // In lieu of maintaining a constant connection to the server, in ZMQ mode, the
        // client updates its internal "connection" object to make sure the right pointers
        // are in place (since in ZMQ mode, each message could be from a different nym 
        // and to a different server.)
        //
        g_OT_API.GetClient()->SetFocusToServerAndNym(*pServerContract, *pMyNym, &OT_API::TransportCallback);
        // NOTE -- This MAY be unnecessary for ProcessUserCommand (since these args are passed
        // in there already) but it's definitely necessary soon after for ProcessServerReply()
        // (which comes next.)
			

//        (OTClient::OT_CLIENT_CMD_TYPE requestedCommand,
//         OTMessage & theMessage,
//         OTPseudonym & theNym,
//         OTServerContract & theServer,
//         OTAccount * pAccount/*=NULL*/,
//         lAmount
//         OTAssetContract * pMyAssetType/*=NULL*/,
//         OTAccount * pHisAcct/*=NULL*/,
//         OTPseudonym * pHisNym/*=NULL*/)

        
        // COMMANDS
        
        if( opt->getValue( 'w' ) != NULL  || opt->getValue( "withdraw" ) != NULL  )
        {
            const long lAmount = atol(opt->getValue( 'w' ));

            OTLog::Output(0, "(User has instructed to withdraw cash...)\n");

            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::notarizeWithdrawal, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         pMyAccount, lAmount))
            {
                bSendCommand = true;
            }
            else
                OTLog::Error("Error processing withdraw command in ProcessMessage.\n");
            // ------------------------------------------------------------------------
        }
        else if( opt->getValue( 't' ) != NULL  || opt->getValue( "transfer" ) != NULL  )
        {
            const long lAmount = atol(opt->getValue( 't' ));

            OTIdentifier HIS_ACCT_ID((str_HisAcct.size() > 0) ? str_HisAcct.c_str():"aaaaaaaa");

            OTLog::Output(0, "User has instructed to send a Transfer command (Notarize Transactions)...\n");
    
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
        
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::notarizeTransfer, theMessage, 
                                                         *pMyNym,  *pServerContract,
                                                         pMyAccount, lAmount, NULL, // asset contract
                                                         NULL, // his Nym
                                                         (str_HisAcct.size() > 0) ? &HIS_ACCT_ID : NULL)) // his acct
            {
                bSendCommand = true;
            }
            else
                OTLog::Error("Error processing notarizeTransactions (transfer) command in ProcessMessage.\n");
        }
        else if( opt->getValue( 'c' ) != NULL  || opt->getValue( "cheque" ) != NULL  )
        {
            OTLog::Output(0, "(User has instructed to write a cheque...)\n");
            
            const long lAmount = atol(opt->getValue( 'c' ));
            
            OTIdentifier HIS_NYM_ID ((str_HisNym.size() > 0)  ? str_HisNym.c_str():"aaaaaaaa"); // todo hardcoding

            g_OT_API.GetClient()->ProcessUserCommand(OTClient::writeCheque, theMessage,
                                                     *pMyNym, *pServerContract,
                                                     pMyAccount, lAmount, NULL, // asset contract
                                                     (str_HisNym.size() > 0)  ? &HIS_NYM_ID : NULL);
        }
        else if( opt->getValue( 'v' ) != NULL  || opt->getValue( "voucher" ) != NULL  )
        {
            OTLog::Output(0, "(User has instructed to withdraw a voucher...)\n");
            
            const long lAmount = atol(opt->getValue( 'v' ));
            
            OTIdentifier HIS_NYM_ID ((str_HisNym.size() > 0)  ? str_HisNym.c_str():"aaaaaaaa");

            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::withdrawVoucher, theMessage,
                                                         *pMyNym, *pServerContract,
                                                         pMyAccount, lAmount, NULL, // asset contract
                                                         (str_HisNym.size() > 0)  ? &HIS_NYM_ID : NULL))
            {
                bSendCommand = true;
            }
            else
                OTLog::Error("Error processing withdraw voucher command in ProcessMessage.\n");

        }

        // make an offer and put it onto a market. 
        else if (opt->getValue( "marketoffer" ) != NULL)
        {
            OTLog::Output(0, "(User has instructed to send a marketOffer command to the server...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::marketOffer, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // for now, keeping it simple. Can add options later.
            {
                bSendCommand = true;
            }
            else
                OTLog::Error("Error processing marketOffer command in ProcessMessage.\n");
            // ------------------------------------------------------------------------
        }

        // ********************************************************
        /*
    bool ProcessUserCommand(OT_CLIENT_CMD_TYPE requestedCommand,
         OTMessage & theMessage,
         OTPseudonym & theNym,
//       OTAssetContract & theContract,
         OTServerContract & theServer,
         OTAccount * pAccount=NULL,
         long lTransactionAmount = 0,
         OTAssetContract * pMyAssetType=NULL,
         OTIdentifier * pHisAcctID=NULL,
         OTIdentifier * pHisNymID=NULL);
         */
        else if(opt->getFlag( "proposepaymentplan" ) )
        {            
            OTLog::Output(0, "(User has instructed to propose a payment plan...)\n");
            
           OTIdentifier HIS_NYM_ID ((str_HisNym.size() > 0)  ? str_HisNym.c_str():"aaaaaaaa");
           OTIdentifier HIS_ACCT_ID((str_HisAcct.size() > 0) ? str_HisAcct.c_str():"aaaaaaaa");
            
            g_OT_API.GetClient()->ProcessUserCommand(OTClient::proposePaymentPlan, theMessage,
                                                     *pMyNym, *pServerContract,
                                                     pMyAccount, 0, pMyAssetContract,
                                                     (str_HisNym.size() > 0)  ? &HIS_NYM_ID : NULL,
                                                     (str_HisAcct.size() > 0) ? &HIS_ACCT_ID : NULL
                                                     );
        }
        // ------------------------------------------------------------------------
        else if(opt->getFlag( "confirmpaymentplan" ) )
        {            
            OTLog::Output(0, "(User has instructed to confirm a payment plan...)\n");
            
            g_OT_API.GetClient()->ProcessUserCommand(OTClient::confirmPaymentPlan, theMessage,
                                                     *pMyNym, *pServerContract,
                                                     NULL); // the account info is already on the plan, right?
        }
        // ------------------------------------------------------------------------
        else if(opt->getFlag( "activatepaymentplan" ) )
        {            
            OTLog::Output(0, "(User has instructed to activate a payment plan...)\n");
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::paymentPlan, theMessage,
                                                     *pMyNym, *pServerContract,
                                                     pMyAccount)) // if user DOES specify an account (unnecessary)
            {                                   // then OT will verify that they match, and error otherwise.
                bSendCommand = true;
            }
            else
                OTLog::Error("Error processing activate payment plan command in ProcessMessage.\n");
        }
        // *******************************************************
        
        else if(opt->getFlag( "depositcheque" ) )
        {            
            OTLog::Output(0, "(User has instructed to deposit a cheque...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::notarizeCheque, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         pMyAccount))
            {
                bSendCommand = true;
            }
            else
                OTLog::Error("Error processing deposit cheque command in ProcessMessage.\n");
            // ------------------------------------------------------------------------
        }
        else if (opt->getFlag( "depositpurse" ) )
        {            
            OTLog::Output(0, "(User has instructed to deposit a cash purse...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::notarizePurse, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         pMyAccount,
                                                         0, // amount (unused here)
                                                         pMyAssetContract))
            {
                bSendCommand = true;
            }
            else
                OTLog::Error("Error processing deposit purse command in ProcessMessage.\n");
            // ------------------------------------------------------------------------
        }
        else if(opt->getFlag( "deposittokens" ) )
        {            
            OTLog::Output(0, "(User has instructed to deposit individual cash tokens...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::notarizeDeposit, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         pMyAccount))
            {
                bSendCommand = true;
            }
            else
                OTLog::Error("Error processing deposit cash tokens command in ProcessMessage.\n");
            // ------------------------------------------------------------------------
        }
        else if( opt->getFlag( 'i' )  || opt->getFlag( "inbox" )  )
        {
            cout << "DISPLAY INBOX CONTENTS HERE... (When I code this. What can I say? Use the GUI.)" << endl ;
        }
        else if( opt->getFlag( 's' ) || opt->getFlag( "sign" ))
        {
            OTLog::Output(0, "(User has instructed to sign a contract...)\n");
            
            g_OT_API.GetClient()->ProcessUserCommand(OTClient::signContract, theMessage,
                                                     *pMyNym, *pServerContract,
                                                     NULL);
        }
        else if( opt->getFlag( 'p' ) || opt->getFlag( "purse" )  )
        {
            cout << "User wants to display purse contents (not coded yet here.)" << endl ;
        }
        else if( opt->getFlag( "verify" )  )
        {
            cout << "User wants to verify a signature on a contract (not coded yet here) " << endl ;
        }
        else if( opt->getFlag( "stat" )   )
        {
            OTLog::Output(0, "User has instructed to display wallet contents...\n");
            
            OTString strStat;
            pWallet->DisplayStatistics(strStat);
            OTLog::vOutput(0, "%s\n", strStat.Get());
        }
        else if(opt->getFlag( 'b' ) || opt->getFlag( "balance" )   )
        {            
            OTLog::vOutput(0, "\n ACCT BALANCE (server-side): %ld\n\n", pMyAccount->GetBalance());
            
            OTPurse * pPurse = g_OT_API.LoadPurse(theServerID, thePurseAssetTypeID, MY_NYM_ID);
            OTCleanup<OTPurse> thePurseAngel(pPurse);
            if (NULL != pPurse)
                OTLog::vOutput(0, " CASH PURSE (client-side): %ld\n", pPurse->GetTotalValue());
        }
        else if( opt->getFlag( 'r' ) || opt->getFlag( "refresh" )   )
        {
            OTLog::Output(0, "(User has instructed to download intermediary files for an asset account...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::getAccount, theMessage, 
                                                         *pMyNym,  *pServerContract,
                                                         pMyAccount))
            {
                bSendCommand = true;
            }
            else
                OTLog::Error("Error processing getAccount command in ProcessMessage.\n");
            // ------------------------------------------------------------------------
        }
        else if( opt->getFlag( "refreshnym" )   )
        {
            OTLog::Output(0, "(User has instructed to download intermediary files for a Nym...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::getNymbox, theMessage, 
                                                         *pMyNym,  *pServerContract,
                                                         NULL))
            {
                bSendCommand = true;
            }
            else
                OTLog::Error("Error processing getNymbox command in ProcessMessage.\n");
            // ------------------------------------------------------------------------
        }

        // ----------------------------------------------------------------------
		//
		
        const OTPseudonym * pServerNym = pServerContract->GetContractPublicNym();
		
		if ((NULL == pServerNym) || (false == pServerNym->VerifyPseudonym()))
        {
            OTLog::vOutput(0, "The server Nym was NULL or failed to verify on contract: %s\n", 
                           strServerID.Get());
            OT_Main_Cleanup();
            return 0;
        }
        //
        // ***********************************************************

        
		if (bSendCommand && pServerNym->VerifyPseudonym())
		{
			OTString strEnvelopeContents(theMessage);
			
			OTEnvelope theEnvelope;
			// Seal the string up into an encrypted Envelope
			theEnvelope.Seal(*pServerNym, strEnvelopeContents);
            
			// -----------------------------------
			
			OTASCIIArmor ascEnvelope(theEnvelope); // ascEnvelope now contains the base64-encoded string of the sealed envelope contents.
			
			if (ascEnvelope.Exists())
			{                
				zmq::socket_t socket(context, ZMQ_REQ);
				
				OTString strConnectPath; strConnectPath.Format("tcp://%s:%d", // todo stop hardcoding.
                                                               strServerHostname.Get(), nServerPort);
				socket.connect(strConnectPath.Get());
				

				// --------------------------------

				zmq::message_t request(ascEnvelope.GetLength());
				memcpy((void*)request.data(), ascEnvelope.Get(), ascEnvelope.GetLength());
				
				int		nSendTries = 0;
				bool	bSuccessSending = false;
				
				// If failure sending, re-tries 5 times GetLatencySendNoTries(), 
                // with 200 ms delay between each. (Maximum of 1 second.)
				//
				while ((nSendTries++ < /*5*/OTLog::GetLatencySendNoTries()) && 
                       (false == (bSuccessSending = socket.send(request, ZMQ_NOBLOCK))))
					OTLog::SleepMilliseconds(/*200*/OTLog::GetLatencySendMs());
                
				if (bSuccessSending)
				{
					//  Get the reply.
					zmq::message_t reply;
					
					int		nReceiveTries = 0;
					bool	bSuccessReceiving = false;
					
					// If failure receiving, re-tries 25 times, with 200 ms delay between each. (Maximum of 5 seconds.)
					//
					while ((nReceiveTries++ < /*25*/OTLog::GetLatencyReceiveNoTries()) && 
                           (false == (bSuccessReceiving = socket.recv(&reply, ZMQ_NOBLOCK))))
						OTLog::SleepMilliseconds(/*200*/OTLog::GetLatencyReceiveMs());
                    
					if (bSuccessReceiving)
					{
						OTASCIIArmor ascServerReply;
						ascServerReply.MemSet(static_cast<const char*>(reply.data()), reply.size());
						
						// --------------------------
						
						OTString	strServerReply;				// Maybe should use g_OT_API.GetClient()->GetNym or some such...
						OTEnvelope theServerEnvelope;
						
						if (theServerEnvelope.SetAsciiArmoredData(ascServerReply))
						{
							bool bOpened = theServerEnvelope.Open(*pMyNym, strServerReply);
                            
							OTMessage * pServerReply = new OTMessage;
							OT_ASSERT(NULL != pServerReply);
                            
							if (bOpened && strServerReply.Exists() && pServerReply->LoadContractFromString(strServerReply))
							{
								// Now the fully-loaded message object (from the server, this time) can be processed by the OT library...
								g_OT_API.GetClient()->ProcessServerReply(*pServerReply); // Client takes ownership and will handle cleanup.
							}
							else
							{
								delete pServerReply;
								pServerReply = NULL;
								OTLog::Error("Error loading server reply from string.\n");
							}
						}
					}
					else
					{
						OTLog::Error("Failed trying to receive message from server.\n");
					}					
				}
				else
				{
					OTLog::Error("Failed trying to send message to server.\n");
				}
			}
		} // if bSendCommand		
        
        OT_Main_Cleanup();
        return 0;
    } // Command line interface (versus below, which is the PROMPT interface.)
    
    // ****************************************************************************
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // -----------------------------------------------------------------------
	//
    //  THE OPEN-TRANSACTIONS PROMPT
    //
    // OT> 
    //
	// Basically, loop:
	//
	//	1) Present a prompt, and get a user string of input. Wait for that.
	//
	//	2) Process it out as an OTMessage to the server. It goes down the pipe.
	//
	//	3) Sleep for 1 second.
	//
	//	4) Awake and check for messages to be read in response from the server.
	//	   Loop. As long as there are any responses there, then process and handle
	//	   them all.
	//	   Then continue back up to the prompt at step (1).
	
    
    
    OTPseudonym * pMyNym = NULL;
    OTWallet * pWallet = NULL;
    OTServerContract * pServerContract = NULL;
    
    // If we got down here, that means there were no commands on the command line 
    // (That's why we dropped into the OT prompt.)
    // However, there still may have been OPTIONS -- and if so, we'll go ahead and
    // load the wallet. (If there were NOT ANY OPTIONS, then we do NOT load the wallet,
    // although there is a COMMAND for doing that.)
    //
    if ( (str_ServerID.size() > 0) || (str_MyNym.size() > 0) )
    {
        if (false == SetupPointersForWalletMyNymAndServerContract(str_ServerID, str_MyNym, 
                                                                  pMyNym, pWallet, pServerContract))
        {
            OT_Main_Cleanup();
            return 0;
        }
    }
    else
        OTLog::Output(0, "\nYou may wish to 'load' then 'stat'.\n"
                      "(FYI, --server SERVER_ID  and  --mynym NYM_ID  were both valid options.)\n"
                      "Also, see:  ~/.ot/command-line-ot.opt for defaults.\n");
    
    // Below this point, pWallet is available and loaded, IF opt->HasOptions().
    // Otherwise, pWallet is NOT loaded, and we're waiting for the Load command.
    
    // Below this point, pMyNym MIGHT be a valid pointer (if it was specified),
    // or MIGHT be NULL. Same with pServerContract. (MIGHT be there.)
    //
    // ***********************************************************
    
    char buf[200] = "";
 	int retVal = 0;
	
	int nExpectResponse = 0;
	
	OTLog::vOutput(4, "Starting client loop.\n", OT_CMD_HEADER_SIZE);
	
	
	// Set the logging level for the network transport code.
#ifndef _WIN32
//	XmlRpc::setVerbosity(1);
#endif
	

	// -----------------------------------------------------------------------

	for(;;)
	{
		buf[0] = 0; // Making it fresh again.
		
		nExpectResponse = 0;
		
		// 1) Present a prompt, and get a user string of input. Wait for that.
		OTLog::Output(0, "\nOT> ");
		
		if (NULL == fgets(buf, 190, stdin)) // Leaving myself 10 extra bytes at the end for safety's sake.
            break;
		
		OTLog::Output(0, ".\n..\n...\n....\n.....\n......\n.......\n........\n.........\n..........\n"
					  "...........\n............\n.............\n");
		
		// so we can process the user input
		std::string strLine = buf;
		
		// Load wallet.xml
		if (strLine.compare(0,4,"load") == 0)
		{
			OTLog::Output(0, "User has instructed to load wallet.xml...\n");

            if (false == SetupPointersForWalletMyNymAndServerContract(str_ServerID, str_MyNym, 
                                                                      pMyNym, pWallet, pServerContract))
            {            
                OT_Main_Cleanup();
                return 0;
            }
            
            continue;
		}
		
		else if ('\0' == buf[0])
		{
			continue;
		}
		else if (strLine.compare(0,4,"test") == 0)
		{
            
            // TODO: Make sure there's no issues with a known plaintext attack.
            // (Not here, but I am doing a similar thing in OTASCIIArmor to maintain a minimum size,
            // due to a bug in some other library that I can't recall at this time.)
            //
			const char * szBlah = "Transaction processor featuring Untraceable Digital Cash, "
			"Anonymous Numbered Accounts, Triple-Signed Receipts, Basket Currencies, and Signed "
			"XML Contracts. Also supports cheques, invoices, payment plans, markets with trades, "
			"and other instruments... it's like PGP for Money.... Uses OpenSSL and Lucre blinded tokens.\n";
			
			
			OTASCIIArmor theArmoredText(szBlah);
			
			OTLog::vOutput(0, "Armored text:\n%s\n", theArmoredText.Get());
			
			
			OTString theFixedText(theArmoredText);
			
			OTLog::vOutput(0, "Uncompressed, etc text:\n%s\n", theFixedText.Get());

			/*
			OTIdentifier	SERVER_ID;
			OTString		SERVER_NAME;
			
			OTServerContract * pServerContract = NULL;
			
			if (NULL == g_OT_API.GetWallet())
			{
				OTLog::Output(0, "The wallet object is still NULL, somehow. Please load it.\n");
				continue;
			}	// Here, for testing, I'm just grabbing the first server in the wallet...
			else if (false == g_OT_API.GetWallet()->GetServer(0, SERVER_ID, SERVER_NAME))
			{
				OTLog::Output(0, "There are no server contracts in the wallet. Try 'load'.\n");
				continue;
			}

			OTMessage theMessage;
			
			if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::checkServerID, theMessage, 
														*pMyNym, *(g_OT_API.GetWallet()->GetServerContract(SERVER_ID)),
														NULL)) // NULL pAccount on this command.
			{
				OTString strEnvelopeContents(theMessage);
				
				OTEnvelope theEnvelope;
				// Seal the string up into an encrypted Envelope
				theEnvelope.Seal(*pMyNym, strEnvelopeContents);
				
				OTASCIIArmor ascEnvelope(theEnvelope); // ascEnvelope now contains the base64-encoded string of the sealed envelope contents.
				
				if (ascEnvelope.Exists())
				{
					OTEnvelope	theNewEnvelope(ascEnvelope);
					OTString	strDecodedText;
					
					theNewEnvelope.Open(*pMyNym, strDecodedText);
					
					OTLog::vOutput(0, "\n\nDECRYPTED TEXT:\n\n%s\n\n", strDecodedText.Get());
				}
			}
			*/
			
			
			/*
			OTData theData(szBlah, strlen(szBlah)+1);
			
//			OTString strBlah(szBlah);
			OTASCIIArmor ascTest;
			
			ascTest.SetData(theData);
			
			OTLog::vOutput(0, "Armored version:\n\n%s\n", ascTest.Get());
			
			OTData theTest;
			
			bool bSuccess = ascTest.GetData(theTest);
			
			OTLog::vOutput(0, "Status: %s \n", (bSuccess ? "TRUE" : "FALSE"));
			*/
			/*{
				OTDB::Storage * pStorage = OTDB::CreateStorageContext(OTDB::STORE_FILESYSTEM, OTDB::PACK_MESSAGE_PACK);
				OT_ASSERT(NULL!=pStorage);
				
				bool bSuccessInit  = pStorage->Init("/Users/au/Projects/Open-Transactions/testwallet/data_folder", "wallet.xml");
				
				if (bSuccessInit)
				{
					{
					std::string strContents("JUST TESTING OUT THE NEW MessagePack CODE!!!!");
					std::string strRetrieved("");
					bool bSuccessStore = pStorage->StoreString(strContents, "temp", "msgpack.tst");
					strRetrieved = pStorage->QueryString("temp", "msgpack.tst");
					OTLog::vOutput(0, "\nPACKED STRING: Success Store:  %s\nQuery:  %s\n", 
								   bSuccessStore ? "TRUE" : "FALSE", strRetrieved.c_str());
					}
					// --------------------------------------------------
					{
					OTDB::BitcoinAcct * pAcct = dynamic_cast<OTDB::BitcoinAcct *>(pStorage->CreateObject(OTDB::STORED_OBJ_BITCOIN_ACCT));
					OT_ASSERT(NULL != pAcct);
					
					pAcct->acct_id		= "jkhsdf987345kjhf8lkjhwef987345";
					pAcct->server_id		= "87345kjhdfs987sfwertwelkj340598t";
					pAcct->bitcoin_acct_name	= "Read-Only Label (Bitcoin Internal acct)";
					pAcct->gui_label			= "Editable Label (Moneychanger)";

					bool bSuccessStore = pStorage->StoreObject(*pAcct, "temp", "msgpack-obj.tst");
					
					OTDB::BitcoinAcct * pAcct2 = 
					dynamic_cast<OTDB::BitcoinAcct *>(pStorage->QueryObject(OTDB::STORED_OBJ_BITCOIN_ACCT,"temp", "msgpack-obj.tst"));
					OTLog::vOutput(0, "\nBITCOIN ACCOUNT: Success Store:  %s\n Success Retrieved:  %s\n Address:  %s\n Name:  %s\n Label:  %s\n", 
								   bSuccessStore ? "TRUE" : "FALSE", 
								   (pAcct2 != NULL) ? "TRUE" : "FALSE", 
								   (pAcct2 != NULL) ? pAcct->acct_id.c_str() : "FALSE", 
								   (pAcct2 != NULL) ? pAcct->bitcoin_acct_name.c_str() : "FALSE", 
								   (pAcct2 != NULL) ? pAcct->gui_label.c_str() : "FALSE");	
					}
					// --------------------------------------------------
					{
					std::string strContents("THIS is a test of the PLAIN STRING system...\nAnd hopefully it will work :)\n");
					std::string strRetrieved("");
					bool bSuccessStore = pStorage->StorePlainString(strContents, "temp", "plaintext.txt");
					strRetrieved = pStorage->QueryPlainString("temp", "plaintext.txt");
					OTLog::vOutput(0, "\nPLAIN STRING: Success Store:  %s\nQuery:  %s\n", 
								   bSuccessStore ? "TRUE" : "FALSE", strRetrieved.c_str());
					}
					// --------------------------------------------------
					
					
				}
				
				delete pStorage;
			}*/
			/*{
				OTDB::Storage * pStorage = OTDB::CreateStorageContext(OTDB::STORE_FILESYSTEM, OTDB::PACK_PROTOCOL_BUFFERS);
				OT_ASSERT(NULL!=pStorage);
				
				bool bSuccessInit  = pStorage->Init("/Users/au/Projects/Open-Transactions/testwallet/data_folder", "wallet.xml");
				
				if (bSuccessInit)
				{
					
					std::string strContents("JUST TESTING OUT THE NEW Protobuf CODE!!!!");
					std::string strRetrieved("");
					bool bSuccessStore = pStorage->StoreString(strContents, "temp", "protobuf.tst");
					strRetrieved = pStorage->QueryString("temp", "protobuf.tst");
					OTLog::vOutput(0, "--------------------- PROTOBUF BELOW -------------\n\n"
								   "PACKED STRING: Success Store:  %s\nQuery:  %s\n", 
								   bSuccessStore ? "TRUE" : "FALSE", strRetrieved.c_str());

					// --------------------------------------------------
					
					OTDB::WalletData * pWallet = dynamic_cast<OTDB::WalletData *>(pStorage->CreateObject(OTDB::STORED_OBJ_WALLET_DATA));
					OT_ASSERT(NULL != pWallet);
					
					// --------------------------------------------------
					
					OTDB::BitcoinAcct * pAcct = dynamic_cast<OTDB::BitcoinAcct *>(pStorage->CreateObject(OTDB::STORED_OBJ_BITCOIN_ACCT));
					OT_ASSERT(NULL != pAcct);
					
					pAcct->acct_id		= "jkhsdf987345kjhf8lkjhwef987345";
					pAcct->server_id		= "87345kjhdfs987sfwertwelkj340598t";
					pAcct->bitcoin_acct_name	= "Read-Only Label (Bitcoin Internal acct)";
					pAcct->gui_label			= "Editable Label (Moneychanger)";
					
					pWallet->AddBitcoinAcct(*pAcct);  // MAKES HIS OWN COPY... (make sure to delete mine.)
						
					bool bProtoStored = pStorage->StoreObject(*pWallet, "temp", "protobuf-obj.tst");
					
					OTLog::vOutput(0, "Storing wallet: %s\n", (bProtoStored ? "SUCCESS" : "FAILURE"));
					
					// --------------------------
					
					OTDB::WalletData * pWallet2 = dynamic_cast<OTDB::WalletData *>(pStorage->QueryObject(OTDB::STORED_OBJ_WALLET_DATA, "temp", "protobuf-obj.tst"));
					OT_ASSERT(NULL != pWallet2);					

					OTDB::BitcoinAcct * pAcct2 = pWallet2->GetBitcoinAcct(0);
					OT_ASSERT(NULL != pAcct2);

					
					OTLog::vOutput(0, "\nWALLET, w/ Bitcoin Acct INSIDE: Store: %s\n Success Retrieved:  %s\n AcctID:  %s\n Name:  %s\n Label:  %s\n", 
								   bSuccessStore ? "TRUE" : "FALSE", 
								   (pAcct2 != NULL) ? "TRUE" : "FALSE", 
								   (pAcct2 != NULL) ? pAcct->acct_id.c_str() : "FALSE", 
								   (pAcct2 != NULL) ? pAcct->bitcoin_acct_name.c_str() : "FALSE", 
								   (pAcct2 != NULL) ? pAcct->gui_label.c_str() : "FALSE");	
					 
					OTDB::Contact * pContact = NULL;
					
					OTDB::Storable * pStorable = pStorage->CreateObject(OTDB::STORED_OBJ_CONTACT);
					
					OT_ASSERT (NULL != pStorable);
					
					pContact = OTDB::Contact::ot_dynamic_cast(pStorable);
					
					OT_ASSERT (NULL != pContact); // Will Assert() out here if cast failed.
					
					OTLog::Output(0, "Dynamic cast success!\n");
				}
				
				delete pStorage;
			}*/
			continue;
		}			
		else if (strLine.compare(0,5,"clear") == 0)
		{
			if (NULL == pMyNym)
			{
				OTLog::Output(0, "No Nym yet available. Try 'load'.\n");
				continue;
			}
			
			pMyNym->RemoveAllNumbers();
			
			pMyNym->SaveSignedNymfile(*pMyNym);
			
			OTLog::Output(0, "Successfully removed all issued and transaction numbers. Saving nym...\n");
			continue;
		}			
        		
		else if (strLine.compare(0,7,"decrypt") == 0)
		{
			if (NULL == pMyNym)
			{
				OTLog::Output(0, "No Nym yet available to decrypt with.\n");
				continue;
			}
			
			OTLog::Output(0, "Enter text to be decrypted:\n> ");
			
			OTASCIIArmor theArmoredText;
			char decode_buffer[200]; // Safe since we only read sizeof - 1
			
			do {
				decode_buffer[0] = 0;
				if (NULL != fgets(decode_buffer, sizeof(decode_buffer)-1, stdin))
				{
					theArmoredText.Concatenate("%s\n", decode_buffer);
					OTLog::Output(0, "> ");
				}
				else 
				{
					break;
				}
			} while (strlen(decode_buffer)>1);
			
			
			OTEnvelope	theEnvelope(theArmoredText);
			OTString	strDecodedText;
			
			theEnvelope.Open(*pMyNym, strDecodedText);
			
			OTLog::vOutput(0, "\n\nDECRYPTED TEXT:\n\n%s\n\n", strDecodedText.Get());
			
			continue;
		}
		
		else if (strLine.compare(0,6,"decode") == 0)
		{
			OTLog::Output(0, "Enter text to be decoded:\n> ");
			
			OTASCIIArmor theArmoredText;
			char decode_buffer[200]; // Safe since we only read sizeof - 1.
			
			do {
				decode_buffer[0] = 0;
				if (NULL != fgets(decode_buffer, sizeof(decode_buffer)-1, stdin))
				{
					theArmoredText.Concatenate("%s\n", decode_buffer);
					OTLog::Output(0, "> ");
				}
				else 
				{
					break;
				}
				
			} while (strlen(decode_buffer)>1);
			
			OTString strDecodedText(theArmoredText);
			
			OTLog::vOutput(0, "\n\nDECODED TEXT:\n\n%s\n\n", strDecodedText.Get());
			
			continue;
		}
		
		else if (strLine.compare(0,6,"encode") == 0)
		{
			OTLog::Output(0, "Enter text to be ascii-encoded (terminate with ~ on a new line):\n> ");
			
			OTString strDecodedText;
			char decode_buffer[200]; // Safe since we only read sizeof - 1.
			
			do {
				decode_buffer[0] = 0;
				
				if ((NULL != fgets(decode_buffer, sizeof(decode_buffer)-1, stdin)) &&
					(decode_buffer[0] != '~'))
				{
					strDecodedText.Concatenate("%s", decode_buffer);
					OTLog::Output(0, "> ");
				}
				else 
				{
					break;
				}
				
			} while (decode_buffer[0] != '~');
			
			OTASCIIArmor theArmoredText(strDecodedText);
			
			OTLog::vOutput(0, "\n\nENCODED TEXT:\n\n%s\n\n", theArmoredText.Get());
			
			continue;
		}
		
		else if (strLine.compare(0,4,"hash") == 0)
		{
			OTLog::Output(0, "Enter text to be hashed (terminate with ~ on a new line):\n> ");
			
			OTString strDecodedText;
			char decode_buffer[200]; // Safe since we only read sizeof - 1.
			
			do {
				decode_buffer[0] = 0;
				
				if ((NULL != fgets(decode_buffer, sizeof(decode_buffer)-1, stdin)) &&
					(decode_buffer[0] != '~'))
				{
					strDecodedText.Concatenate("%s\n", decode_buffer);
					OTLog::Output(0, "> ");
				}
				else 
				{
					break;
				}
				
			} while (decode_buffer[0] != '~');
			
			OTIdentifier theIdentifier;
			theIdentifier.CalculateDigest(strDecodedText);
			
			OTString strHash(theIdentifier);
			
			OTLog::vOutput(0, "\n\nMESSAGE DIGEST:\n\n%s\n\n", strHash.Get());
			
			continue;
		}
		
		else if (strLine.compare(0,4,"stat") == 0)
		{
			OTLog::Output(0, "User has instructed to display wallet contents...\n");
			
            if (pWallet)
            {
                OTString strStat;
                pWallet->DisplayStatistics(strStat);
                OTLog::vOutput(0, "%s\n", strStat.Get());
			}
            else
                OTLog::Output(0, "No wallet is loaded...\n");
            
			continue;
		}
		
		else if (strLine.compare(0,4,"help") == 0)
		{
			OTLog::Output(0, "User has instructed to display the help file...\n");
			
            OTString strRAWFileDefault, strFileDefault;
            strRAWFileDefault.Format("%s%s%s", OT_FOLDER_DEFAULT, OTLog::PathSeparator(), OT_PROMPT_HELPFILE);
            OTLog::TransformFilePath(strRAWFileDefault.Get(), strFileDefault);
            
            OTString strResult;
            strResult.Format("more %s", strFileDefault.Get());
			system(strResult.Get()); // todo security audit this in case of security issues.
		            
			continue;
		}
		
		else if (strLine.compare(0,4,"quit") == 0)
		{
			OTLog::Output(0, "User has instructed to exit the wallet...\n");
			
			break;
		}
		
		
		// ------------------------------------------------------------------------------			
	
        /*
         --myacct   (ACCT ID)
         --mynym    (NYM ID)
         --mypurse  (ASSET TYPE ID)
         
         --toacct   (ACCT ID)
         --tonym    (NYM ID)
         --topurse  (ASSET TYPE ID)
         
         OTPseudonym *		GetNymByIDPartialMatch(const std::string PARTIAL_ID);
         OTServerContract *	GetServerContractPartialMatch(const std::string PARTIAL_ID);
         OTAssetContract *	GetAssetContractPartialMatch(const std::string PARTIAL_ID);
         OTAccount *         GetAccountPartialMatch(const std::string PARTIAL_ID);
         */  
        
        
        if (NULL == pServerContract)
        {
            OTLog::Output(0, "Unable to find a server contract. Please restart using the option:  --server SERVER_ID\n"
                          "(Where SERVER_ID is the server ID. Partial matches ARE accepted.)\n");
            continue;
        }
        
      	
		// You can't just connect to any hostname and port.
		// Instead, you give me the Server Contract, and *I'll* look up all that stuff FOR you...
		// (We verify this up here, but use it at the bottom of the function once the message is set up.)
		//
		int			nServerPort = 0;
		OTString	strServerHostname;
		
		if (false == pServerContract->GetConnectInfo(strServerHostname, nServerPort))
		{
			OTLog::Error("Failed retrieving connection info from server contract.\n");
			continue;
		}
		
		// ------------------------------------------------------------------------------			
        
        // I put this here too since I think it's required in all cases below.
        //
        if (NULL == pMyNym) // Todo maybe move this check to the commands below (ONLY the ones that use a nym.)
        {
            OTLog::Output(0, "Unable to find My Nym. Please restart and use the option:\n"
                          "   --mynym USER_ID\n"
                          "(Where USER_ID is the Nym's ID. Partial matches ARE accepted.)\n");
            continue;
        }

		// ------------------------------------------------------------------------------			
        
		bool bSendCommand	= false; // Determines whether to actually send a message to the server.
		
		OTMessage theMessage;
		
		// If we can match the user's request to a client command,
		// AND theClient object is able to process that request into
		// theMessage, then we send it down the pipe.
		
        // *******************************************************************************
        
        
        // In lieu of maintaining a constant connection to the server, in RPC mode, the
        // client updates its internal "connection" object to make sure the right pointers
        // are in place (since in RPC mode, each message could be from a different nym 
        // and to a different server.)
        //
        g_OT_API.GetClient()->SetFocusToServerAndNym(*pServerContract, *pMyNym, &OT_API::TransportCallback);
        // NOTE -- This MAY be unnecessary for ProcessUserCommand (since these args are passed
        // in there already) but it's definitely necessary soon after for ProcessServerReply()
        // (which comes next.)
        
        // -------------------------------------------------------------------------
        
        // 'check server ID' command
        if (buf[0] == 'c')
        {
            OTLog::vOutput(0, "(User has instructed to send a checkServerID command to the server...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::checkServerID, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command (so far).
            {				
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing checkServerID command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        // register new user account 
        else if (buf[0] == 'r')
        {
            OTLog::Output(0, "(User has instructed to send a createUserAccount command to the server...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::createUserAccount, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing createUserAccount command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        // ALL MESSAGES BELOW THIS POINT SHOULD ATTACH A REQUEST NUMBER IF THEY EXPECT THE SERVER TO PROCESS THEM.
        // (Handled inside ProcessUserCommand)
        
        // checkUser
        else if (buf[0] == 'u')
        {
            OTLog::Output(0, "(User has instructed to send a checkUser command to the server...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::checkUser, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing checkUser command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        // register new asset account 
        else if (buf[0] == 'a')
        {
            OTLog::Output(0, "(User has instructed to send a createAccount command to the server...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::createAccount, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing createAccount command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        // issue a new asset type 
        else if (!strcmp(buf, "issue\n"))
        {
            OTLog::Output(0, "(User has instructed to send an issueAssetType command to the server...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::issueAssetType, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing issueAssetType command in ProcessMessage: %s\n", buf);
            // ------------------------------------------------------------------------
        }
        
        // issue a new basket asset type 
        else if (!strcmp(buf, "basket\n"))
        {
            OTLog::Output(0, "(User has instructed to send an issueBasket command to the server...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::issueBasket, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing issueBasket command in ProcessMessage: %s\n", buf);
            // ------------------------------------------------------------------------
        }
        
        // exchange in/out of a basket currency 
        else if (!strcmp(buf, "exchange\n"))
        {
            OTLog::Output(0, "(User has instructed to send an exchangeBasket command to the server...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::exchangeBasket, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing exchangeBasket command in ProcessMessage: %s\n", buf);
            // ------------------------------------------------------------------------
        }
        
        // make an offer and put it onto a market. 
        else if (!strcmp(buf, "offer\n"))
        {
            OTLog::Output(0, "(User has instructed to send a marketOffer command to the server...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::marketOffer, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing marketOffer command in ProcessMessage: %s\n", buf);
            // ------------------------------------------------------------------------
        }
        
        // Set a Server Contract's client-side name (merely a label.) 
        else if (!strcmp(buf, "setservername\n"))
        {
            OTLog::Output(0, "(User wants to set a Server Contract's client-side name...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::setServerName, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                //					bSendCommand = true; // No message needed. Local data only.
            }
            // ------------------------------------------------------------------------
        }
        
        // Set an Asset Contract's client-side name (merely a label.) 
        else if (!strcmp(buf, "setassetname\n"))
        {
            OTLog::Output(0, "(User wants to set an Asset Contract's client-side name...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::setAssetName, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                //					bSendCommand = true; // No message needed. Local data only.
            }
            // ------------------------------------------------------------------------
        }
        
        // Set a Nym's client-side name (merely a label.) 
        else if (!strcmp(buf, "setnymname\n"))
        {
            OTLog::Output(0, "(User wants to set a Nym's client-side name...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::setNymName, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                //					bSendCommand = true; // No message needed. Local data only.
            }
            // ------------------------------------------------------------------------
        }
        
        // Set an Asset Account's client-side name (merely a label.) 
        else if (!strcmp(buf, "setaccountname\n"))
        {
            OTLog::Output(0, "(User wants to set an Asset Account's client-side name...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::setAccountName, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                //					bSendCommand = true; // No message needed. Local data only.
            }
            
            // ------------------------------------------------------------------------
        }
        
        // sendUserMessage
        else if (buf[0] == 's')
        {
            OTLog::Output(0, "(User has instructed to send a sendUserMessage command to the server...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::sendUserMessage, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing sendUserMessage command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        
        // get nymbox 
        else if (buf[0] == 'y')
        {
            OTLog::Output(0, "(User has instructed to send a getNymbox command to the server...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::getNymbox, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing getNymbox command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        // get inbox 
        else if (buf[0] == 'i')
        {
            OTLog::Output(0, "(User has instructed to send a getInbox command to the server...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::getInbox, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL))
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing getInbox command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        // get outbox 
        else if (buf[0] == 'o')
        {
            OTLog::Output(0, "(User has instructed to send a getOutbox command to the server...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::getOutbox, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL))
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing getOutbox command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        // deposit cheque
        else if (buf[0] == 'q')
        {
            OTLog::Output(0, "User has instructed to deposit a cheque...\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::notarizeCheque, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL))
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing deposit cheque command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        // deposit purse
        else if (buf[0] == 'p')
        {
            OTLog::Output(0, "(User has instructed to deposit a purse containing cash...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::notarizePurse, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL))
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing deposit command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        // deposit tokens
        else if (buf[0] == 'd')
        {
            OTLog::Output(0, "(User has instructed to deposit cash tokens...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::notarizeDeposit, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL))
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing deposit command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        // withdraw voucher
        else if (buf[0] == 'v')
        {
            OTLog::Output(0, "User has instructed to withdraw a voucher (like a cashier's cheque)...\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::withdrawVoucher, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing withdraw voucher command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        // withdraw cash
        else if (buf[0] == 'w')
        {
            OTLog::Output(0, "(User has instructed to withdraw cash...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::notarizeWithdrawal, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing withdraw command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        // activate payment plan
        else if (!strcmp(buf, "activate\n"))
        {
            OTLog::Output(0, "User has instructed to activate a payment plan...\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::paymentPlan, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing payment plan command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        // get account 
        else if (!strcmp(buf, "get\n"))
        {
            OTLog::Output(0, "(User has instructed to send a getAccount command to the server...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::getAccount, theMessage, 
                                                         *pMyNym,  *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing getAccount command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        // get contract 
        else if (!strcmp(buf, "getcontract\n"))
        {
            OTLog::Output(0, "(User has instructed to send a getContract command to the server...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::getContract, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing getContract command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        // ------------------------------------------------------------------------
        
        else if (!strcmp(buf, "propose\n"))
        {
            OTLog::Output(0, "(User has instructed to propose a payment plan...)\n");
            
            g_OT_API.GetClient()->ProcessUserCommand(OTClient::proposePaymentPlan, theMessage,
                                                     *pMyNym, *pServerContract,
                                                     NULL); // User owns Merchant (recipient) account
            continue;
        }
        
        else if (!strcmp(buf, "confirm\n"))
        {
            OTLog::Output(0, "(User has instructed to confirm a payment plan...)\n");
            
            g_OT_API.GetClient()->ProcessUserCommand(OTClient::confirmPaymentPlan, theMessage,
                                                     *pMyNym, *pServerContract,
                                                     NULL); // the account info is already on the plan, right?
            continue;
        }
        
        // ------------------------------------------------------------------------
        
        else if (!strcmp(buf, "cheque\n"))
        {
            OTLog::Output(0, "(User has instructed to write a cheque...)\n");
            
            g_OT_API.GetClient()->ProcessUserCommand(OTClient::writeCheque, theMessage,
                                                     *pMyNym, *pServerContract,
                                                     NULL); // It will ascertain the account inside the call.			
            continue;
        }

        // sign contract 
        // This doesn't message the server, but it DOES require the user's Nym to be loaded.
        else if (!strcmp(buf, "signcontract\n"))
        {
            OTLog::Output(0, "(User has instructed to sign a contract...)\n");
            
            g_OT_API.GetClient()->ProcessUserCommand(OTClient::signContract, theMessage,
                                                     *pMyNym, *pServerContract,
                                                     NULL);
            continue;            
        }
        
        // get mint 
        else if (!strcmp(buf, "getmint\n"))
        {
            OTLog::Output(0, "(User has instructed to send a getMint command to the server...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::getMint, theMessage, 
                                                         *pMyNym,  *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing getMint command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        // notarize transfer 
        else if (buf[0] == 't')
        {
            OTLog::Output(0, "(User has instructed to send a Transfer command (Notarize Transactions) to the server...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::notarizeTransfer, theMessage, 
                                                         *pMyNym,  *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing notarizeTransactions command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        // getRequest
        else if (buf[0] == 'g')
        {
            OTLog::Output(0, "(User has instructed to send a getRequest command to the server...)\n");
            
            // ------------------------------------------------------------------------------			
            // if successful setting up the command payload...
            
            if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::getRequest, theMessage, 
                                                         *pMyNym, *pServerContract,
                                                         NULL)) // NULL pAccount on this command.
            {
                bSendCommand = true;
            }
            else
                OTLog::vError("Error processing getRequest command in ProcessMessage: %c\n", buf[0]);
            // ------------------------------------------------------------------------
        }
        
        // getTransactionNum
        else if (buf[0] == 'n')
        {
            // I just coded (here) for myself a secret option (for testing)...
            // Optionally instead of JUST 'n', I can put n <number>, (without brackets) and
            // this code will add that number to my list of issued and transaction numbers.
            // I already have the ability to clear the list, so now I can add numbers to it as well.
            // (Which adds to both lists.)
            // I can also remove a number from the transaction list but LEAVE it on the issued list,
            // for example by writing a cheque and throwing it away.
            //
            // This code is for testing and allows me to find and patch any problems without
            // having to re-create my data each time -- speeds up debugging.
            //
            long lTransactionNumber = ((strlen(buf) > 2) ? atol(&(buf[2])) : 0);
            
            if (lTransactionNumber > 0)
            {
                OTString strServerID;
                pServerContract->GetIdentifier(strServerID);
                
                pMyNym->AddTransactionNum(*pMyNym, strServerID, lTransactionNumber, true); // bool bSave=true
                
                OTLog::vOutput(0, "Transaction number %ld added to both lists (on client side.)\n", 
                               lTransactionNumber);
            }
            
            else 
            {
                OTLog::Output(0, "(User has instructed to send a getTransactionNum command to the server...)\n");
                
                // ------------------------------------------------------------------------------			
                // if successful setting up the command payload...
                
                if (g_OT_API.GetClient()->ProcessUserCommand(OTClient::getTransactionNum, theMessage, 
                                                             *pMyNym,  *pServerContract,
                                                             NULL)) // NULL pAccount on this command.
                {
                    bSendCommand = true;
                }
                else
                    OTLog::vError("Error processing getTransactionNum command in ProcessMessage: %c\n", buf[0]);
            }
            
            // ------------------------------------------------------------------------
        }
        
        else 
        {
            if( 1 )
            {
                //gDebugLog.Write("unknown user command in ProcessMessage in main.cpp");
                OTLog::Output(0, "\n");
                //				OTLog::vError( "unknown user command in ProcessMessage in main.cpp: %d\n", buf[0]);
            }		
            continue;
        }
		
            
		// ************************************************************************
            
		
		const OTPseudonym * pServerNym = pServerContract->GetContractPublicNym();
		
//		OTString strExtra1("TESTPUBKEYCLI.txt"), strExtra2(*pServerContract);
		
//		(const_cast<OTPseudonym *>(pServerNym))->SavePublicKey(strExtra1);
		
		if (bSendCommand && (NULL != pServerNym) && pServerNym->VerifyPseudonym())
		{
			OTString strEnvelopeContents(theMessage), strEnvelopeContents2(theMessage);
			// Save the ready-to-go message into a string.
//			theMessage.SaveContract(strEnvelopeContents);
			
			OTEnvelope theEnvelope;//, theEnvelope2;
			// Seal the string up into an encrypted Envelope
			theEnvelope.Seal(*pServerNym, strEnvelopeContents);
//			theEnvelope2.Seal(*pMyNym, strEnvelopeContents2);
							  
			// -----------------------------------
			
			OTASCIIArmor ascEnvelope(theEnvelope); // ascEnvelope now contains the base64-encoded string of the sealed envelope contents.
//			OTASCIIArmor ascEnvelope2(theEnvelope2);
			
			if (ascEnvelope.Exists())
			{
//				OTLog::vError("DEBUG Envelope addressed to Nym ID: %s. Contents: \n%s\n Size: %ld, Nym: \n%s\n Server Contract:\n%s\n", 
//							  theIDString.Get(), ascEnvelope.Get(),ascEnvelope.GetLength(), strExtra1.Get(), strExtra2.Get());
//				
//				OTEnvelope theTestEnvelope(ascEnvelope2);
//				OTString strTestOutput2;
//				bool bOpened2 = theTestEnvelope.Open(*pMyNym, strTestOutput2);
//
//				OTLog::vError("DEBUG Opening a similar envelope... Contents: \n%s\n", strTestOutput2.Get());

				
				zmq::socket_t socket(context, ZMQ_REQ);
				
				OTString strConnectPath; strConnectPath.Format("tcp://%s:%d", strServerHostname.Get(), nServerPort);
				socket.connect(strConnectPath.Get());
				
				// --------------------------------
//				OTPayload thePayload;
//				bool bSetEnvelope = thePayload.SetEnvelope(theEnvelope);
				
//				bool GetEnvelope(OTEnvelope & theEnvelope) const; // Envelope retrieved from payload.
//				bool SetEnvelope(const OTEnvelope & theEnvelope); // Envelope copied into payload to prepare for sending.
				

				zmq::message_t request(ascEnvelope.GetLength());
				memcpy((void*)request.data(), ascEnvelope.Get(), ascEnvelope.GetLength());
				
				int		nSendTries = 0;
				bool	bSuccessSending = false;
				
				// If failure sending, re-tries 5 times, with 200 ms delay between each. (Maximum of 1 second.)
				//
				while ((nSendTries++ < 5) && (false == (bSuccessSending = socket.send(request, ZMQ_NOBLOCK))))
					OTLog::SleepMilliseconds(200); // todo stop hardcoding. (For now I needed non-blocking so this is much better than before.)

				// Here's our connection...
//#if defined (linux)
//				XmlRpcClient theXmlRpcClient(strServerHostname.Get(), nServerPort, 0); // serverhost, port.
//#elif defined (_WIN32) 
//				XmlRpcClient theXmlRpcClient(strServerHostname.Get(), nServerPort, "fellowtraveler"); // serverhost, port, value that crashes if NULL.
//#else
//				XmlRpcClient theXmlRpcClient(strServerHostname.Get(), nServerPort); // serverhost, port.
//#endif
				
				// -----------------------------------------------------------
				//
				// Call the OT_XML_RPC method (thus passing the message to the server.)
				//
//				XmlRpcValue oneArg, result;		// oneArg contains the outgoing message; result will contain the server reply.
//				oneArg[0] = ascEnvelope.Get();	// Here's where I set the envelope string, as the only argument for the rpc call.
//				
//				if (theXmlRpcClient.execute("OT_XML_RPC", oneArg, result)) // The actual call to the server. (Hope my envelope string isn't too long for this...)

				if (bSuccessSending)
				{
					//  Get the reply.
					zmq::message_t reply;
					
					int		nReceiveTries = 0;
					bool	bSuccessReceiving = false;
					
					// If failure receiving, re-tries 25 times, with 200 ms delay between each. (Maximum of 5 seconds.)
					//
					while ((nReceiveTries++ < 25) && (false == (bSuccessReceiving = socket.recv(&reply, ZMQ_NOBLOCK))))
						OTLog::SleepMilliseconds(200); // todo stop hardcoding. (And probably change how I send/receive, but for now I needed non-blocking...)

//					std::string str_Result;
//					str_Result.reserve(reply.size());
//					str_Result.append(static_cast<const char*>(reply.data()), reply.size());
					
					if (bSuccessReceiving)
					{
						OTASCIIArmor ascServerReply;
						ascServerReply.MemSet(static_cast<const char*>(reply.data()), reply.size());
						
//						OTPayload theRecvPayload;
//						theRecvPayload.SetPayloadSize(reply.size());
//						memcpy((void*)theRecvPayload.GetPayloadPointer(), reply.data(), reply.size());

						// --------------------------
						
						OTString	strServerReply;				// Maybe should use g_OT_API.GetClient()->GetNym or some such...
						OTEnvelope theServerEnvelope;
						
						if (theServerEnvelope.SetAsciiArmoredData(ascServerReply))
						{
							bool bOpened = theServerEnvelope.Open(*pMyNym, strServerReply);

							OTMessage * pServerReply = new OTMessage;
							OT_ASSERT(NULL != pServerReply);

							if (bOpened && strServerReply.Exists() && pServerReply->LoadContractFromString(strServerReply))
							{
								// Now the fully-loaded message object (from the server, this time) can be processed by the OT library...
								g_OT_API.GetClient()->ProcessServerReply(*pServerReply); // Client takes ownership and will handle cleanup.
							}
							else
							{
								delete pServerReply;
								pServerReply = NULL;
								OTLog::Error("Error loading server reply from string.\n");
							}
						}
					}
					else
					{
						OTLog::Error("Failed trying to receive message from server.\n");
					}					
				}
				else
				{
					OTLog::Error("Failed trying to send message to server.\n");
				}
			}
		} // if bSendCommand		
	} // for
	
	// -----------------------------------------------------------

		
	OTLog::Output(0, "Exiting OT prompt.\n");
	
    OT_Main_Cleanup();
	
	return 0;
}




































