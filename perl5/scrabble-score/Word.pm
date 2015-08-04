package Word;

use Carp;
use Readonly;
use warnings;
use strict;
use Exporter;
use vars qw($VERSION @ISA @EXPORT @EXPORT_OK %EXPORT_TAGS);

$VERSION     = 1.00;
@ISA         = qw(Exporter);
@EXPORT      = ();
@EXPORT_OK   = qw();
%EXPORT_TAGS = ( DEFAULT => [qw()],);

#Letter                           Value
#A, E, I, O, U, L, N, R, S, T       1
#D, G                               2
#B, C, M, P                         3
#F, H, V, W, Y                      4
#K                                  5
#J, X                               8
#Q, Z                               10
Readonly::Hash my %letter_scores => (
    a => 1,
    b => 3,
    c => 3,
    d => 2,
    e => 1,
    f => 4,
    g => 2,
    h => 4,
    i => 1,
    j => 8,
    k => 5,
    l => 1,
    m => 3,
    n => 1,
    o => 1,
    p => 3,
    q => 10,
    r => 1,
    s => 1,
    t => 1,
    u => 1,
    v => 4,
    w => 4,
    x => 8,
    y => 4,
    z => 10,
);

#constructor
sub new($)  {
    my $class = shift(@_);        # $_[0] contains the class name
    my $word = shift(@_);

    my $self = {};        # the internal structure we'll use to represent the class
    
    # Init the data
    $$self{word} = $word;
    
    bless( $self, $class );    # make $self an object of class $class

    return $self;
}

sub score {
    my $self = shift(@_);
    my @options = @_;
    
    my $score = 0;
    
    # Trim whitespace
    my $word = $$self{word};
    $word =~ s/^\s*//;
    $word =~ s/\s*$//;
    
    # Calculate the single letter score for each letter in the word
    for (my $i = 0; $i < length($word); $i++) {
        my $lc_letter = lc(substr($word, $i, 1));
        $score += $letter_scores{$lc_letter};
    }
    
    # If there are any double/tripple letter scores then compute them
    my $option_multipler = 1;
    for (my $i = 0; $i < scalar(@options); $i += 2) {
        my $option = $options[$i];
        my $option_mult_factor = $options[$i+1];
        
        if ($option eq "double") {
            $option_multipler = $option_multipler * (2 ** $option_mult_factor); 
        }
        elsif ($option eq "triple") {
            $option_multipler = $option_multipler * (3 ** $option_mult_factor); 
        }
        else {
            croak "Unknown option $option!\n";
        }
    }
    
    return $score * $option_multipler;
}
