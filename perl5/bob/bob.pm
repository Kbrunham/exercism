
        package Bob;

use warnings;
use strict;
use utf8;
use Unicode::Normalize;
use Exporter;
use vars qw($VERSION @ISA @EXPORT @EXPORT_OK %EXPORT_TAGS);

$VERSION     = 1.00;
@ISA         = qw(Exporter);
@EXPORT      = ();
@EXPORT_OK   = qw(hey);
%EXPORT_TAGS = ( DEFAULT => [qw(&hey)],
                );
sub hey($) {
	my $input = shift(@_);
	
	# Remove all accents
	$input = NFKD($input);
	print "Word == $input\n";

	
	#Bob answers 'Sure.' if you ask him a question.
	#He answers 'Whoa, chill out!' if you yell at him.
	#He says 'Fine. Be that way!' if you address him without actually saying anything.
	#He answers 'Whatever.' to anything else.

	# Shouting is not finding any lower case letter, but finding some upper case letters
	if (($input !~ m/[a-z]/) && ($input =~ m/[A-Z]/))
	{
		return "Whoa, chill out!";
	}
	# Empty text
	elsif ($input =~ m/^\s*$/)
	{
		return "Fine. Be that way!";
	}
    # Text ending in ?
	elsif ($input =~ m/\?\s*$/)
    {
        return "Sure.";
    }
	else
	{
		return "Whatever.";
	}
	
	return undef;

}

1;
      